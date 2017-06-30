# Circular Linked List

## 1. Struct

- `CircularListNode` : Singly 때와 같다. 데이터와 다음 노드를 가리키는 포인터로 이루어져있음
- `CircularList`
    + 현재 원소 개수 저장
    + Singly 때와 다르게 헤더 노드를 쓰는 것이 아니라 노드 포인터를 사용

## 2. Abstract Data Type

### 2.1 addCLElement : 원소 추가

#### 2.1.1 첫 번째 원소로 추가 && 공백 리스트

- 빈 리스트에 처음 원소를 추가하는 경우다.
- CircularList의 pLink(헤드 포인터)가 새로운 노드를 가리키게 한다.
- 순환해야하므로 새로운 노드의 pLink가 자신(새로운 노드)을 가리키게 한다.

#### 2.1.2 첫 번째 원소로 추가 && 리스트 원소 존재

- 이미 첫 번째 노드가 존재하고 있는데 첫 번째로 추가하는 경우
- 일단 마지막 노드를 찾는다.
    + pLastNode라는 포인터를 새로 선언하고 처음부터 계속 다음으로 반복해서 이동한다.
    + pLastNode의 pLink가 기존 첫 노드를 가리킬 때 멈춘다. `pLastNode->pLink == pList->pLink`
- 링크 정리
    + CircularList pLink(헤드 포인터)가 새로운 노드를 가리키게 한다.
    + 새로운 노드의 pLink가 기존 첫 노드를 가리키게 하는데 마지막 노드의 pLink를 활용한다.
    + 마지막 노드의 pLink가 새로운 노드를 가리키게 한다.

#### 2.1.3 리스트 중간 위치에 추가

- 찾으려는 position 인덱스 크기만큼 반복을 돌아서 원하는 위치 직전까지 간다.
- 새로운 노드의 pLink를 이전노드의 pLink 값으로 만든다.
- 이전 노드의 pLink가 새로운 노드를 가리키도록 한다.

### 2.2 removeCLElement : 원소 삭제

#### 2.2.1 첫 번째 노드 && 원소 개수 1개(삭제하면 공백리스트가 됨)

- 첫 번째이자 마지막인 단 하나의 노드를 제거하는 경우다.
- CircularList pLink(헤드 포인터)가 가리키는 노드를 free
- CircularList pLink에 NULL 대입

#### 2.2.2 첫 번째 노드 && 원소 개수 N개(N > 1)

- 헤드포인터와 마지막 노드의 pLink가 "두 번째" 노드를 가리키도록 해야한다.
- 삭제할 노드인 첫 번째 노드를 새로운 포인터 pDelNode 변수가 가리키도록 한다.
- 먼저 마지막 노드를 찾는다.
    + 헤드포인터부터 계속 넘어가면서 다음 조건될 때까지 반복한다.
    + `pLastNode->pLink == pList->pLink`
- 링크 정리
    + 마지막 노드의 pLink가 두 번째 노드, 즉 pDelNode의 pLink가 가리키는 노드를 가리키도록 한다.
    + 헤드 포인터가 두 번째 노드를 가리키도록 한다.
    + free(pDelNode)

#### 2.2.3 N 번째 노드(N > 1)

- 찾고자 하는 position index를 활용해서 직전 노드를 찾고 변수 pPreNode에 저장
- pPreNode의 pLink를 이용해서 삭제할 노드를 찾고 pDelNode에 저장
- pPreNode의 pLink에 pDelNode의 pLink 값을 대입
- free(pDelNode)

### 2.3 기타

- `getCLElement` : 포지션 인덱스를 하나하나 깎아가면서 반복 돌아서 찾으면 된다.
- `createCircularList` : CircularList의 크기만큼 메모리 할당하고 모든 값을 0으로 할당
- `getCircularListLength` : 현재 원소 개수 리턴
- `displayCircularList` : 모든 원소 출력
- `deleteCircularList` : clear 한 다음 CircularList free
- `clearCircularList` : 전체 원소 개수가 0이 될 때까지 헤드 노드를 지운다.
