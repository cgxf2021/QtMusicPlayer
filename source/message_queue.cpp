#include "../header/message_queue.hpp"

MessageQueue::~MessageQueue() {}

MessageQueue *MessageQueue::getInstance() {
  static MessageQueue messageQueue;
  return &messageQueue;
}

// 入队
void MessageQueue::push(Song *song) {
  if (!song) {
    return;
  }
  std::lock_guard<std::mutex> guard(m_mutex);
  m_songQueue.push_back(song);
}

// 出队
Song *MessageQueue::pop() {
  Song *song = nullptr;
  if (m_songQueue.isEmpty()) {
    return song;
  } else {
    std::lock_guard<std::mutex> guard(m_mutex);
    if (!m_songQueue.isEmpty()) {
      song = m_songQueue.front();
      m_songQueue.pop_front();
    }
  }
  return song;
}

// 队空
bool MessageQueue::isEmpty() {
  std::lock_guard<std::mutex> guard(m_mutex);
  return m_songQueue.isEmpty();
}

// 队大小
int MessageQueue::size() {
  std::lock_guard<std::mutex> guard(m_mutex);
  return m_songQueue.size();
}
