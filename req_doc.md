REQUIREMENTS DOCUMENT FOR TEAM PROJECT 

 

Aim of this project: 

We have created 2 searching algorithms. One is Binary Search and the other one is Linear Search. What we focused on is with different sizes and ranges of lists which algorithm can be selected to search for each list to perform better. From what we learnt we know that linear search is easier to code comparing to binary search. For the few number of elements in lists linear search usually performs better than binary search. However, as number of elements in lists increase, we know that performance of linear search algorithm gets poorer while the binary search begins the performs better. With the following tables which are the output of our program we proofed this claim. 

 

The Way We Coded the Program: 

First of all, we implemented the searching algorithms (linear and binary search) and we searched for each element in source list to see if there is any of them in our destination list. We compared both of them with respect to operation count and time taken to each sort. To clarify that our searching algorithms work fine we compared the number of intersections for each sort and as you can see from the tables, they are always same. Details on how to compile and run the program is in the README file.  

 

Result: 

As expected, for the lists between the values 1-10 linear search performed better it did a smaller number of operations. However, as our range gets larger like 1-200, binary search has become more efficient than linear search. Hence, what we can conclude from this project is that, it is more efficient to use linear search on small range of elements, however, binary search should be the one to use for the large range of elements. 


 
|BINARY SEARCH | Source | Destination | Op Count | Time(micro seconds) | AnB | A/B |
|:------------|:-------|:------------|:---------|:--------------------|:----|:----|
|List1(1-5)|5|-|58|5|5|0|
|List2(1-10)|-|10|-|-|-|-|

|LINEAR SEARCH | Source | Destination | Op Count | Time(micro seconds) | AnB | A/B |
|:------------|:-------|:------------|:---------|:--------------------|:----|:----|
|List1(1-5)|5|-|25|5|5|0|
|List2(1-10)|-|10|-|-|-|-|


|BINARY SEARCH | Source | Destination | Op Count | Time(micro seconds) | AnB | A/B |
|:------------|:-------|:------------|:---------|:--------------------|:----|:----|
|List1(0-20)|21|-|121|19|11|10|
|List2(10-20)|-|11|-|-|-|-|

|LINEAR SEARCH | Source | Destination | Op Count | Time(micro seconds) | AnB | A/B |
|:------------|:-------|:------------|:---------|:--------------------|:----|:----|
|List1(0-20)|21|-|187|19|11|10|
|List2(10-20)|-|11|-|-|-|-|


|BINARY SEARCH | Source | Destination | Op Count | Time(micro seconds) | AnB | A/B |
|:------------|:-------|:------------|:---------|:--------------------|:----|:----|
|List1(1-200)|200|-|2058|159|101|99|
|List2(100-200)|-|101|-|-|-|-|

|LINEAR SEARCH | Source | Destination | Op Count | Time(micro seconds) | AnB | A/B |
|:------------|:-------|:------------|:---------|:--------------------|:----|:----|
|List1(1-200)|200|-|15251|513|101|99|
|List2(100-200)|-|101|-|-|-|-|


|BINARY SEARCH | Source | Destination | Op Count | Time(micro seconds) | AnB | A/B |
|:------------|:-------|:------------|:---------|:--------------------|:----|:----|
|List1(0-10000)|10001|-|183853|11982|5001|5000|
|List2(5000-10000)|-|5001|-|-|-|-|

|LINEAR SEARCH | Source | Destination | Op Count | Time(micro seconds) | AnB | A/B |
|:------------|:-------|:------------|:---------|:--------------------|:----|:----|
|List1(0-10000)|1001|-|37517502|1359451|5001|5000|
|List2(5000-10000)|-|5001|-|-|-|-|



ms = micro seconds
Op Count = operation counter 
AnB = common elements found 
A/B = elements not found from source list 




 

 

 

 
	
