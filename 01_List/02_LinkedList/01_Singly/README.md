# Singly Linked List

## 1. Struct

- `ListNode` : 노드를 나타낸다. 데이터와 다음 노드를 가리키는 포인터 존재
- `LinkedList` : 링크드 리스트
    + 현재 원소 개수 저장
    + 헤더 노드: 노드의 추가, 삭제 구현을 간편하게 하는 dummy node

## 2. Abstract Data Type

### 2.1 createLinkedList : 생성

- LinkedList의 사이즈(int 1개, node 1개)만큼 메모리 할당
- memset으로 모든 값을 0으로
- 딱히 다른 값을 대입하고 하는건 없다. 위 작업으로 끝

### 2.2 addLLElement : 원소 추가

- LinkedList 포인터, 인덱스 포지션, 노드 element를 매개변수로 받는다.
- 이전 노드와 새로운 노드를 가리킬 포인터를 둘 선언한다.
    + 이전 노드는 해당 매개변수로 받은 포지션에 위치한 노드를 가리키기 위함이고 하나하나 넘어가면서 찾아서 대입할 것이다.
    + 새로운 노드는 새롭게 메모리를 할당해서 데이터를 넣고, 해당 포지션에 끼워넣을 것이다.
- 역시 매개변수로 받은 position이 양수인지, 현재 원소 개수 이하인지 검증한다.
- `pNewNode = (ListNode*)malloc(sizeof(ListNode));`
    + 새롭게 메모리 할당
    + pNewNode는 노드가 저장될 메모리 공간을 가리키는 포인터
- `*pNewNode = element;`
    + pNewNode가 가리키는 곳, 즉 새로 할당한 메모리에 element를 대입하겠다.
    + element는 노드 구조체이고 저렇게 대입하면 해당 구조체의 값이 모두 복사된다.
    + 그리고 다음 노드를 가리키는 링크는 일단 NULL로 대입
    + `pNewNode->data = element.data` 형태로 데이터만 복사하는게 아니라 이렇게 통으로 값을 복사하는 이유는 나중에 Node의 데이터의 형태가 바뀌었을 때 코드를 수정할 필요가 없기 때문
- pPreNode, 이전 노드를 가리키게 될 이 포인터는 정해진 포지션까지 하나하나 타넘어가야한다. pList의 headerNode를 이용해서 position 숫자만큼 반복해서 다음 노드로 넘어간다.
- 링크 변경
    + 이전 노드의 다음 노드는 새로운 노드의 링크가 가리키도록 하고
    + 이전 노드의 링크는 새로운 노드를 가리키도록 한다.
    + 즉 "이전 노드 -> 새로운 노드 -> 원래 다음 노드"
- 원소 개수 ++

### 2.3 removeLLElement : 원소 삭제

- 탐색할 때 사용할 ListNode 포인터 하나, 삭제할 Node를 가리킬 포인터 하나 선언
- position으로 받은 인덱스로 반복해서 탐색하면 삭제할 노드 바로 이전 노드를 가리킬 수 있다.
- 링크 변경
    + 이전 노드가 가리키는 노드를 삭제할 노드 포인터로 가리킨다
    + 이전 노드의 링크 포인터를 삭제할 노드의 링크 포인터가 가리키는 노드로 바꾼다.
- 삭제할 노드 포인터를 활용해 free
- 원소 개수 --

### 2.4 원소 get, display

- get은 position만큼 반복해서(이번엔 preNode를 고르는게 아니라 해당 Node를 구하는거라서 반복 조건이 미만에서 이하로 바뀜) 해당 노드를 찾고 리턴한다.
- display는 Array List에서 한 것과 같은 방식으로 모든 값을 출력

### 2.5 기타

- LinkedList 삭제: clearLinkedList를 호출하고 LinkedList를 free
- LinkedList 데이터 초기화: 내부 노드들을 맨 뒤에서부터 하나하나 재귀로 찾아가면서 free해줘야한다. 현재 코드는 그렇게 되어있지 않다.
- LinkedList 길이 : 현재 원소 개수 리턴
- 비었는지 여부 : 현재 원소 개수가 0이면 TRUE 아니면 FALSE
