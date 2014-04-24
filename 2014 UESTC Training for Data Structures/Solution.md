2014 UESTC Training for Data Structures
=======================================

__Problem B__
--------------
* Segment tree, Binary Indexed Tree

Just the ordinary operations of the data structure , no more further skills.

__Problem C__
--------------
* Segment Tree(lazy-tag)

Segment Tree , which should maintain functions that can modify and query intervals. So , `lazy-tag` should be used to optimise the data structure.

__Problem E__
--------------
* Binary Indexed Tree

The problem can be transformed into "Count the numbers before and after which are smaller than a number". `BIT[num]` indicates the numbers smaller than or equal to `num`, using Binary Indexed Tree to maintain it. Go through the numbers from head to tail and then from tail to head, thus we can store the value of each number in arrays `F[]` and `G[]`. In the end, all you need is to multipy `F[]` with `G[]`.

__Problem F__
--------------
* Binary Indexed Tree

Glancing at it, you may think this problem should be solved by Planar Segment Tree. However , the ranges of the data deny it. :(
We should adapt some tricks solving this problem. Because all the query are like this form `(0 , 0 , x , y)`. So we should `sort` the coordinates at first , `y` as the first key word and `x` as the second. After this , we can use `BIT[num]` to check how many numbers _currently_ are smaller than or equal to `num`. Obviously, here `num` should be the `x` coordinate.

> We should add all the coordinates by __1__ in order to maintain the `BIT[]` easily.
  i.e.
	`arr[i].x ++;`
	`arr[i].y ++;`

__Problem H__
--------------
* Heap

Here we can maintain 2 heaps to solve this problem. We create a `MaxHeap` and a `MinHeap`. Each time we insert a number to the array, we either insert it into the `MaxHeap` or the `MinHeap`. So , the median number will only be either the top of `MaxHeap` or the top of the `MinHeap`. We should also adapt some stratigies to maintain the two heaps in order that the sizes of them are equal or the delta is only __1__.

    We should disscuss the following situations:

    + num < maxHeapTop
        - maxHeap.size() <= minHeap.size()  
        - maxHeap.size() == minHeap.size() + 1
    + maxHeapTop <= num <= minHeapTop
        - maxHeap.size() <= minHeap.size()
        - maxHeap.size() == minHeap.size() + 1
    + num > minHeapTop
        - minHeap.size() <= maxHeap.size()
        - minHeap.size() == maxHeap.size() + 1

__Problem J__
--------------
* Trie

Just the ordinary implementations of Trie , no more further skills.

__Problem K__
--------------
* Stack

Just note that each number vary from another. So just implement a stack simply. That's OK.



------------------------
If you have some questions or find something wrong in my solutions, just contact me in by the following two methods:

* Telephone: (+86) 135 4139 1821
* E-mail: Allen.3.ysj@gmail.com

> The source code will be staged on my github:
URL: `https://github.com/Allen3/CDOJ`
