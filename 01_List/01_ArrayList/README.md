# Array List

## 1. 기본

- array를 이용한 리스트
- 장점: 원소를 get할 때 인덱스를 활용하기 때문에 한 번의 연산으로 가능하다. 즉 read가 빠르다.
- 단점
    + 처음 ArrayList를 생성할 때 크기를 지정하기 때문에 원소 개수 제한이 있다.
    + 원소를 추가, 제거할 때 뒤 인덱스의 원소들을 모두 당기거나 밀어야하기 때문에 연산이 많아진다. `O(n)`

## 2. Abstract Data Type

### 2.1 기본 Struct

- `ArrayListNode` : 정수형 데이터 하나를 가지는 구조체. ArrayList의 원소 하나하나를 뜻한다.
- `ArrayList` : ArrayList를 나타내는 구조체
    + `maxElementCount` : 전체 사이즈 값
    + `currentElementCount` : 현재 가지고 있는 원소 개수
    + `pElement` : ArrayListNode를 원소로 가지는 배열을 가리키는 포인터

### 2.2 createArrayList : 생성

- 최대 원소 개수를 매개변수로 받는다.
- ArrayList 크기만큼 메모리 할당
- ArrayList의 원소 값 초기화한다.
    + 전체 사이즈 값은 매개변수 받은걸로 대입
    + 현재 원소개수는 0으로
    + 배열은 임시로 NULL 대입
- pElement에 배열을 새로 만들어 가리키도록 한다. 배열은 ArrayListNode 사이즈의 전체 원소개수를 곱해서 메모리 할당
- memeset으로 모든 배열의 값을 0으로 할당

### 2.3 addALElement: 원소 추가

- ArrayList를 가리키는 포인터를 받아서 매개변수로 받은 position에, 받은 element를 넣는 함수. 성공 여부를 0, 1로 리턴한다.
- 받은 ArrayList 포인터가 NULL은 아닌지, ArrayList가 꽉 차진 않았는지, position으로 받은 값이 0보다 작거나 배열을 중간에 텅 비게 하도록 현재 개수보다 더 크진 않는지 체크한다.
- ArrayList 내의 배열에서 맨 뒤 원소부터 앞으로 가면서 한칸씩 뒤로 민다.
- 해당 position에 element 대입
- 현재 원소개수 ++
- 위 작업이 에러 없이 잘 이뤄졌으면 리턴값을 TRUE로 바꾼다. 처음에 리턴값을 FALSE로 세팅했기 때문에 마지막에 리턴값을 바로 리턴해주면 된다.

### 2.4 removeALElement: 원소 제거

- ArrayList를 가리키는 포인터와, 지워야할 원소의 position을 받아서 제거한다.
- ArrayList를 가리키는 포인터가 NULL은 아닌지, 지워야할 position 인덱스가 0보다 작진 않은지, 현재 갖고 있는 원소들 인덱스 범위 내에 있는지 검사
- 지워야할 position부터 시작해서 바로 뒤 원소를 한 칸씩 앞으로 당긴다. 덮어 씀
- 현재 갖고 있는 원소 개수를 --

### 2.5 get, display: 원소 read, 전체 read

- get은 ArrayList 포인터와 position 인덱스를 받아서 해당 포지션의 ArrayListNode를 가리키는 포인터를 리턴한다.
- display는 최대 원소 개수와 현재 원소 개수, 그리고 배열의 원소들을 모두 반복을 돌면서 print한다.

### 2.6 ETC

- `isArrayListFull` : current count와 max count가 같으면 꽉 찬 것
- `getArrayListLength` : current count를 리턴
- `deleteArrayList` : ArrayList의 내부 배열을 먼저 free하고, ArrayList를 free
- `addALElementFirst` : 0 인덱스에 원소 추가
- `addALElementLast` : 마지막 인덱스, 즉 current count에 원소 추가
