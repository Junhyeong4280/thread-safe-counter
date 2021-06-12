# thread-safe-counter
20163286 Jun Hyeong Park

OS Environment : Ubuntu Linux 18.04 

The number of repetitions : for 1000000 repetiation

Runtime comparison between mutex and semaphore

- Mutex 
![mutex_3번돌려 본것](https://user-images.githubusercontent.com/84069022/121778702-09ed0b80-cbd3-11eb-89a4-60a2a3fd2c4d.JPG)


- Semaphore
![semapho_3번돌려본것](https://user-images.githubusercontent.com/84069022/121778707-16716400-cbd3-11eb-830b-e56fdffb19ac.JPG)


Run time on average : 

- mutex \n

 real = 1.041 [sec]
 user = 1.563 [sec]
 sys = 0.481 [sec]

- semaphore 

real = 2.221 [sec]
user = 3.081 [sec]
sys = 1.248 [sec]


- Analysis and Consideration :
- Basically, semaphore and mutex were common methods for controlling multiple process or threads' access to shared resources, which were time to check for different execution methods.
The big difference between semaphore and mutex is convenient to describe as a toilet. Mutex is to carry the key to the bathroom and wait for one person to come out, and the three spaces are three spaces, and semaphore is the one that can go in every time one person is left out of three spaces.
Considering the reason for the difference in execution time in this way,When you repeat the same loop, it would save more time to block shared resources at once and solve them at once. Semaphore is a method of re-executing and checking every time it goes out, so I think the system of checking a little more takes more time.
Either way, programming for that purpose would be the right way to use the right way.
