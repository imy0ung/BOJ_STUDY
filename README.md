**BOJ_STUDY with Cpp**
---
## 백준에서 사용하는 기본적인 c++ 팁들
```c++
#include <iostream> = cpp에서의 입출력
  
#include <cstdio> = c언어의 stdio.h
  
using namespace std; = std 생략 가능

ios::sync_with_stdio(0) =  c와 동기를 끊어서 cin과 cout의 속도를 올려준다. (c의 입출력 사용불가능)

cin.tie(0) = cin의 속도를 올려준다.

auto = type을 알아서 

getlin(cin,s) = 공백을 포함해서 문자열을 받아준다. 단, type이 string이어야한다.

for (auto e : c) = range-based for loop

for (int i = 0; i < n; i++) fill(arr[i], arr[i] + n, -1) = 2차원 배열을 -1로 다 초기화시켜줌

stl next_permutation << 겨울방학때 백트래킹 공부하면서 알아두자
```
## STL(Standard Template Library)

## 1. ``` #include <vector> ```
벡터 자료형, 동적으로 할당된 자료형이기 때문에, 배열보다 자유로움

iterator = 컨테이너의 포인터 ex) ``` vector<int>:: iterator it;```
  
 * ```vector<int> v``` = 비어있는 vector v를 생성
 * ```vector<int> v(5)``` = 초기화 된 5개의 원소를 가지는 vector 생성
 * ```vector<int> v(5,2)``` = 2로 초기화된 5개의 원소를 가지는 vector v 생성
 * ```vector<int> v2(v1)``` = v2에 v1를 복사
  
 * ```vec.begin()``` = 벡터 자료형의 첫번째 원소의 주소 반환
 * ```vec.end()``` = 벡터 자료형의 마지막 원소의 주소 반환
 * ```vec.front()``` = 벡터 자료형의 첫번째 원소 반환
 * ```vec.back()``` = 벡터 자료형의 마지막 원소 반환
 * ```vec.size()``` = 벡터 자료형의 크기
 * ```vec.push_back()``` = 마지막에 데이터 추가
 * ```vec.pop_back()``` = 마지막에 데이터 삭제
 * ```vec.at(n)``` = 벡터 자료형의 n번째 원소의 값을 반환 (일반적인 경우, O(n) = 1)
 * ```vec.erase(iterator 1, iterator 2)``` = iterator 1 부터 iterator 2까지 지워준다.

## 2. ``` #include <algorithm> ```

  2-1) pair
  * 두 가지 자료형을 하나의 쌍으로 묶을 수 있음
  * pair <type1, type2>
  * p.first , p.second 로 접근
  * make_pair<type1, type2> = pair 생성
  
  2-2) stable_sort
  * 원래의 순서를 손상시키지 않으면서 정렬하는 것 - boj) 10814
  
  2-3) sort
  * ``` sort(iterator1, iterator2, cmp)```
  * return a < b 부등호 주의!! 같으면 cmp에서 true값을 계속 반환해서 error가 발생한다.
  
  2-5) unique(iterator1, iterator2) = 정렬된 컨테이너에서 iterator1 부터 iterator2 까지 중복되는 값은 맨 뒤로 보내준다. vector의 erase랑 같이 사용해서, 컨테이너의 중복되는 값을 제거해줄 수 있다.
  
  2-6) lower_bound(iterator1, iterator2, 해당값) = 이진검색트리로 정렬된 컨테이너에서 해당값보다 같거나 큰 값을 찾는 알고리즘. 반환값은 iterator. 아무래도 이진트리다 보니까 logn의 복잡도가 나와서 for문으로 이용하여 위치 찾는 것 보다 훨씬 빠르다..! 오름차순으로 정렬되어있어야 하는 걸 주의하자!
  
  2-7) upper_bound(iterator1, iterator2, 해당값) = 이진검색트리로 정렬된 컨테이너에서 해당값을 처음으로 초과하는 값을 찾는 알고리즘. 반환값은 iterator

## 3. ``` #include <queue> ```
  3-1) queue
  * 자료구조 FIFO
  * queue<type>
  * ```push()``` = 데이터 추가
  * ```pop()``` = 데이터 삭제
  * ```front()``` = 첫번째 원소 반환
  * ```back()``` = 마지막 원소 반환
  * ```size()``` = queue의 크기 
  * ```empty()``` = 비어있으면 1을 반환해줌

  3-2) priority queue
  * 우선순위가 있는 queue
  * 기본적으로 내림차순부터 설정되어있다.
  * priority_queue<int, vector<int>, greater<int>> pq; = 오름차순 방법
  
## 4. ``` #include<stack> ```
  4-1) stack
  * 자료구조 LIFO
  * ```push()``` = top에 데이터 추가
  * ```pop()``` = top에서 데이터 뽑기
  * ```size()``` = stack의 크기
  * ```empty()``` = 비어있으면 1을 반환해줌

  4-2) duque
  * 자료구조 deque (양방향으로 확장 가능한 자료구조)
  * vector와 같이, 인덱스로 접근가능하지만, iterator가 순차적이지 않음
  * ```pop_back()```, ```pop_front()```, ```push_back()```, ```push_front()```, ```erase()```, ```clear()```, ```insert()``` 

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

## 7. ```#include <unordered_set>```
* 선언 방식 : ```unorderd_set<type> s ```
* 중복허용을 하지 않음
* 삽입 : ```s.insert()```
* 지우기 : ```s.erase()``` 지우면 1을 반환 못지우면 0을 반환
* 사이즈 : ```s.size()```
* 찾기 : ```s.find(n)``` 찾은 값의 iterator를 반환, 찾지못한다면, s.end()를 반환

## 8. ```#include <unordered_map>```
* key에 대응되는 value를 찾아주는 stl
* 선언 방식 : ```unordered_map<key_type, value_type> m ```
* 중복허용을 하지 않음
* 삽입 : ```s.insert()```
* 지우기 : ```s.erase()``` 지우면 1을 반환 못지우면 0을 반환
* 사이즈 : ```s.size()```
* 찾기 : ```s.find(n)``` 찾은 값의 iterator를 반환, 찾지못한다면, s.end()를 반환

## 9. ```#include <list> ```

9-1) iterator
* ```begin()``` : 첫번째 iterator 반환
* ```end()``` : 마지막 iterator 반환 (마지막 값이 아니라 맨 마지막 노드임)

9-2) 삽입
* ```push_front(element)``` : 리스트 맨 앞에 원소 추가
* ```push_back(element)``` : 리스트 맨 뒤에 원소 추가
* ```insert(iterator, element)``` : 해당 iterator 앞에 원소 추가

9-3) 삭제
* ```pop_front()``` : 리스트 맨 앞의 원소 삭제
* ```pop_back()``` : 리스트 맨 뒤의 원소 삭제
* ```erase(iterator)``` : 해당 iterator 원소 삭제
