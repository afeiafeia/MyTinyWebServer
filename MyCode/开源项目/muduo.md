## Recator的关键结构
(1)Channel Class
每个Channel 对象自始自终只属于一个EventLoop、只属于一个IO线程、只负责一个文件描述符（fd）的IO事件的分发，但是Channel对象不拥有这个fd
Channel会把不同的IO事件分发给不同的回调



## echo

