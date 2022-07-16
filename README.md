**BOJ_STUDY with Cpp**
---

```#include <iostream>``` = cpp에서의 입출력
  
```#include <cstdio>``` = c언어의 stdio.h
  
```using namespace std;``` = std 생략 가능

## STL(Standard Template Library)

## 1. ``` #include <vector> ```
벡터 자료형, 동적으로 할당된 자료형이기 때문에, 배열보다 자유로움

iterator = 컨테이너의 포인터 ex) ``` vector<int>:: iterator it;```
  
 * ```vector<int> v``` = 비어있는 vector v를 생성
 * ```vector<int> v(5)``` = 초기화 된 5개의 원소를 가지는 vector 생성
 * ```vector<int> v(5,2)``` = 2로 초기화된 5개의 원소를 가지는 vector v 생성
 * ```vector<int> v2(v1)``` = v2에 v1를 복사
  
 * vec.begin() = 벡터 자료형의 첫번째 원소의 주소 반환
 * vec.end() = 벡터 자료형의 마지막 원소의 주소 반환
 * vec.front() = 벡터 자료형의 첫번째 원소 반환
 * vec.back() = 벡터 자료형의 마지막 원소 반환
 * vec.size() = 벡터 자료형의 크기
 * vec.push_back() = 마지막에 데이터 추가
 * vec.pop_back() = 마지막에 데이터 삭제
 * vec.at(n) = 벡터 자료형의 n번째 원소의 값을 반환 (일반적인 경우, O(n) = 1)

## 2. ``` #include <algorithm> ```

  2-1) pair
  * 두 가지 자료형을 하나의 쌍으로 묶을 수 있음
  * pair <type1, type2>
  * p.first , p.second 로 접근
  * make_pair<type1, type2> = pair 생성
  
  2-2) stable_sort
  * 원래의 순서를 손상시키지 않으면서 정렬하는 것 - boj) 10814

## 3. ``` #include <queue> ```
  3-1) 자료구조 FIFO
  * queue<type>
  * push() = 데이터 추가
  * pop() = 데이터 삭제
  * front() = 첫번째 원소 반환
  * back() = 마지막 원소 반환
  * size() = queue의 크기 
  * empty() = 비어있으면 1을 반환해줌

  3-2) priority queue
  * 우선순위가 있는 queue
  * 기본적으로 내림차순부터 설정되어있다.
  * priority_queue<int, vector<int>, greater<int>> pq; = 오름차순 방법
  
## 4. ``` #include<stack> ```
* 자료구조 LIFO
* push() = top에 데이터 추가
* pop() = top에서 데이터 뽑기
* size() = stack의 크기
* empty() = 비어있으면 1을 반환해줌

## 5. ``` #include <set> ```
* 중복을 허락하지 않는 key의 집합, 자동으로 오름차순으로 정렬해준다.
* insert() = 데이터 추가
* begin() = 맨 첫번째 원소의 iterator 반환
* end() = 맨 마지막 원소의 iterator 반환
* size() = stack의 크기
* empty() = 비어있으면 1을 반환해줌

## 6. ``` #include <map> ```
* key와 value의 쌍으로 저장하는 자료형
* key의 중복이 허용되지 않음, 자동으로 오름차순 정렬
* [] 연산자 제공
* insert(make_pair(key,value))
* erase(key) = 해당 key를 가르치는 원소 삭제
* size() = stack의 크기
* empty() = 비어있으면 1을 반환해줌
