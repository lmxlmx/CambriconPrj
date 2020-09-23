#ifndef MULTIMEDIA_CNCODEC_V2_COMMON_SEMAPHORE_H_
#define MULTIMEDIA_CNCODEC_V2_COMMON_SEMAPHORE_H_

#include <chrono>
#include <condition_variable>
#include <mutex>

template <typename T = int>
class CncodecSemaphore {
 public:
  explicit CncodecSemaphore(T count = 0) noexcept : count_(count) {}
  void wait() noexcept {
    std::unique_lock<std::mutex> lock(mtx_);
    cv_.wait(lock, [=] { return count_ > 0; });
    --count_;
  }
  bool wait_for(unsigned int timeout_ms) noexcept {
    std::unique_lock<std::mutex> lock(mtx_);
    if (cv_.wait_for(lock, std::chrono::milliseconds(timeout_ms), [=] { return count_ > 0; })) {
      --count_;
      return true;
    }
    return false;  // if timeout, return false
  }
  void post() noexcept {
    std::lock_guard<std::mutex> lock(mtx_);
    ++count_;
    cv_.notify_one();
  }

  ~CncodecSemaphore() = default;
  CncodecSemaphore(const CncodecSemaphore&) = delete;
  CncodecSemaphore& operator=(const CncodecSemaphore&) = delete;
  CncodecSemaphore(CncodecSemaphore&&) = delete;
  CncodecSemaphore& operator=(CncodecSemaphore&&) = delete;

 private:
  mutable std::mutex mtx_;
  mutable std::condition_variable cv_;
  T count_;
};
#endif  //  MULTIMEDIA_CNCODEC_V2_COMMON_SEMAPHORE_H_
