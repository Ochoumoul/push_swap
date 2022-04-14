# Push_swap (42 Network)

This project is about sorting some data on **stack**, the data will be a bunch of decimal numbers. In this project you're only allowed to uses a couple of stacks and some simple instruction like rotation and a reverse rotation, swap which which switch the 2 first elements on the **stack** bellow i will explain what every instruction does that we're allowed to use on this project

## **Operations:**
- Swap: swap the 2 first elements on the stack. And do nothing if there is less than 2 elements.
- Rotation: the first element becomes the last.
- Reverse rotation: the last element becomes the first.
- Swap both: calls the swap operation on both stacks.
- Rotate both: calls the rotate operation on both stacks.
- Reverse rotate both: call the reverse rotate operation on both stacks.

## How i solved the problem:

Solving this problem i've used the longest increasing subsequent algorithm, which helps me find the list of numbers that is already sorted. then i push to **stack B** the elements that do not belong to the list. After that i should figure out the best element that could be returned from **stack B** to **stack A**. Figuring out the best element requires determining how far that element and its pair from the top of stack. When you find the best element you have nothing left to do but doing the necessary instructions to make that element and its pair a the top of the stacks then push that element from **stack B** to **stack A**. when the **stack B** size is zero you might find yourself with an unsorted stack (am talking about **stackA**) but once you top the minimum element you'll find the your stack have been sorted successfully. 

## Small Demo (Image does use LIS Algorithm for sort)

<img src="/media/push_swap_demo.git" />
