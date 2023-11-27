#ifndef MESSAGE_QUEUE_HPP_
#define MESSAGE_QUEUE_HPP_

#include <QQueue>
#include <mutex>

#include "song.hpp"

class MessageQueue {
 private:
  MessageQueue() = default;
  ~MessageQueue();
  MessageQueue(const MessageQueue &) = delete;
  MessageQueue &operator=(const MessageQueue &) = delete;
  // 存储数据接口的队列
  QQueue<Song *> m_songQueue;
  // 互斥量
  std::mutex m_mutex;

 public:
  static MessageQueue *getInstance();
  // 入队
  void push(Song *song);
  // 出队
  Song *pop();
  // 队空
  bool isEmpty();
  // 队大小
  int size();
};

#endif  // !MESSAGE_QUEUE_HPP_
