#include "./net/EventLoop.h"
#include "./Thread.h"
#include "./Log.h"
#include <unistd.h>
#include <stdio.h>
using namespace afa;
afa::Logger::ptr curLog = LOG_NAME("EVENTLOOP");

void callback()
{
  LOG_DEBUG(curLog)<<"callback()";
  printf("callback(): pid = %d, tid = %d\n", getpid(), CurrentThread::tid());
}
void threadFunc()
{
  for(int i=0;i<1;i++)
  {
    LOG_DEBUG(curLog)<<"WorkThreadInfor";
  }
  int x = afa::CurrentThread::tid();
  assert(EventLoop::GetEventLoopOfCurThread() == NULL);
  EventLoop loop;
  assert(EventLoop::GetEventLoopOfCurThread() == &loop);
  loop.RunInLoop(callback);
  //loop.Loop();
}
int main()
{
    LOG_DEBUG(curLog)<<"MainThreadInfor";
    EventLoop loop;
    assert(EventLoop::GetEventLoopOfCurThread() == &loop);
    
    {
      Thread thread(threadFunc,"WorkThread1");
      thread.Start();

    }
    //Thread thread2(threadFunc,"WorkThread2");

    //thread2.Start();
    //sleep(3);
    //thread.Join();
    //thread2.Join();
    loop.Loop();
}