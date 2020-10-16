﻿# 每周总结可以写在这里

       对于深度优先DFS的写法慢慢变得熟练，但是对于广度优先BFS的代码还比较陌生，周末要找点题做。当我做二分查找的题目时，原本以为很简单，实际发现自己弄不清边界，什么时候用<，什么时候用<=傻傻分不清导致代码写出来运行结果一直是内存越界，搞了我一整个晚上。希望复习的时候能想清楚边界问题，以及什么时候带“=”号什么时候不带“=”号。

       对于二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方，我的思路是：
①暴力求解，遍历整个数组同时比较vec[i]和vec[i + 1]的大小，出线vec[i] > vec[i + 1]的时候，i + 1就是我们要找的位置。
②二分法，令left = 0，right = vec.size() - 1得到数组的左右端点，取int mid = (left + right) / 2 得到数组中点，然后比较vec[mid]、vec[left]和vec[right]之间的大小。我们假设是升序半有序数组，那么数组右端点的值vec[right]是肯定小于左端点的值vec[left]的，如果vec[mid] > vec[left]说明0 ~ mid之间是有序的，无序的位置在mid的右侧，这个时候让left = mid + 1，然后mid = (left + right) / 2得到新的中间点；如果vec[mid] < vec[right]，说明该数组在mid ~ right之间有序，无序的位置在mid左侧，那么令right = mid，mid = (left + right) / 2得到新的mid；重复上述比较过程，最终找到该数组无序的位置。