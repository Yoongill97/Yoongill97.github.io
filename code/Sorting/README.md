# Sorting Algorithm 비교하기

Bubble, Selection, Insertion, Shell, Heap, Quick 등의 정렬을 직접구현해보고, 그 성능을 비교해보았다.

![Sorting_main](/assets/images/Sorting_main.png)


1000까지의 무작위 숫자를 배열에 넣을 수 있도록 하고, 실행시간을 측정할 수 있도록 하였다.

배열의 크기는 2의 5승부터 20승까지 늘려가며, 각 알고리즘의 실행시간을 측정한다.

![Sorting_main2](/assets/images/Sorting_main2.png)


각 구현된 정렬 알고리즘 직전과 직후의 시간의 차이로 실행시간을 측정한다.

![time1](/assets/images/time_example1.png)

출력은 이런식으로 나오게 된다.


## 랜덤한 데이터에 대한 실행시간

![random](/assets/images/time_random.png)


![graph_ran](/assets/images/graph_random.png)


무작위로 정렬되어 있는 데이터에 대한 실행시간이다.


## 이미 정렬된 데이터에 대한 실행시간

![sorted](/assets/images/time_sorted.png)


![graph_sorted](/assets/images/graph_sorted.png)


이미 정렬이 된 데이터에 대한 실행시간이다.

랜덤한 데이터에서 보여줬던 우수한 성능과는 상이하게, Quick Sort 알고리즘이 Bubble Sort 알고리즘과 비슷한 실행시간을 보여준다.


### Quick Sort의 재귀 호출, 스택 오버플로우

입력 데이터 수가 65536부터 재귀호출하는 형식의 Quick Sort 알고리즘에서 오버플로우가 발생하며, 실행시간 측정이 어려웠다.

![QuickSort](/assets/images/QuickSort.png)


재귀호출을 하지 않는 방식으로 Quick Sort를 구현하여 다시 진행하였다.

![QuickSort2](/assets/images/Quick2.png)


무작위로 정렬되어 있는 데이터에 대한 실행시간을 기존 알고리즘과 비교한 결과 큰 차이가 없음을 확인하였고, 이미 정렬된 데이터와 역으로 정렬된 데이터에 대한 Quick Sort는 이 소스코드로 진행하였다.


## 역으로 정렬된 데이터에 대한 실행시간

![resorted](/assets/images/time_resorted.png)


![graph_resorted](/assets/images/graph_resorted.png)


역으로 정렬된 데이터에 대한 실행시간이다.

이미 정렬된 데이터에 대한 성능과 비슷한 모습을 보이고 있다.

하지만 눈여결 볼 점은, Insertion Sort는 정렬된 데이터에서 0에 가까운 실행시간을, 역정렬된 데이터에선 무작위로 정렬된 데이터에서보다 2배에 가까운 실행시간을 가진다.


## 정리

![graph1](/assets/images/graph1.png)


Bubble, Selection, Shell, Heap 과 같은 정렬 알고리즘은 각각의 시간복잡도와 메모리 사용량은 다르지만, 실행시간이 데이터의 상태에 민감하지 않다는 것을 알 수 있다.

다시 말하면, 위의 알고리즘은 어떠한 상황에서도 안정적인 동작을 보여준다.

![Insertion](/assets/images/Insertion.png)


Insertion Sort의 경우는, 사람과 가장 비슷하다고 생각할 수 있다. 정렬이 되어있는 데이터를 입력받을 수록, 그 실행시간은 빨라진다.

Quick Sort에서 최악의 경우는 pivot 설정에 문제가 있을 때인데, 이는 이미 정렬이 된 데이터, 역으로 정렬된 데이터, 모두 같은 값을 가진 데이터 등의 상황이다.


![time](https://velog.velcdn.com/images%2Fjaeyunn_15%2Fpost%2Fff10da68-72c8-465e-9da8-9260b26db9a9%2F%E1%84%89%E1%85%B3%E1%84%8F%E1%85%B3%E1%84%85%E1%85%B5%E1%86%AB%E1%84%89%E1%85%A3%E1%86%BA%202021-03-07%20%E1%84%8B%E1%85%A9%E1%84%92%E1%85%AE%2011.32.57.png)


정렬 별 시간복잡도와 공간복잡도 표를 보면, 위에서 직접 확인한 결과를 잘 이해할 수 있다.