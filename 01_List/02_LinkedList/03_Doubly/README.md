# Doubly Linked List

## 1. Struct

- `DoublyListNode` : 데이터, 왼쪽 링크, 오른쪽 링크 포인터로 구성되어있다.
- `DoublyList` : 현재 원소 개수, 헤더 노드로 구성

## 2. Abstract Data Type

### 2.1 createDoublyList : 생성

- `DoublyList`의 사이즈만큼 메모리 할당
- 헤더 노드의 양 포인터 모두 헤더 노드 자신을 가리키도록 한다.

### 2.2 addDLElement : 원소 추가

- position 값을 활용해 반복을 돌아서 추가하려는 위치 바로 이전 노드를 찾는다.
- 링크 정리
    + 새로운 노드의 왼쪽은 이전 노드를, 오른쪽은 이전노드의 다음 노드를 가리키도록 대입
    + 이전 노드의 다음 노드는 새로운 노드로 재 대입
    + 새로운 노드의 다음 노드의 왼쪽은 새로운 노드로 재 대입
- 원소 개수 ++

### 2.3 removeDLElement : 원소 삭제

- position 값을 활용해 반복을 돌아서 추가하려는 위치 바로 이전 노드를 찾는다.
- 이전 노드의 오른쪽 노드가 우리가 삭제하려는 노드. 새로운 변수 pDelNode로 할당해둔다.
- 링크 정리
    + 이전 노드의 우측을 삭제할 노드의 우측 노드로 대입
    + 삭제할 노드의 우측 노드의 좌측을 이전노드로 대입
- free(pDelNode)
- 원소 개수 --

### 2.4 기타

- `getDLElement` : 포지션 값으로 반복 돌아서 노드 리턴
- `displayDoublyList` : 원소 출력
- `deleteDoublyList` : clear 함수 호출한 다음 DoublyList free
- `clearDoublyList` : 원소 개수가 0이 될 때까지 첫 번째 노드 삭제
- `getDoublyListLength` : 원소 개수 리턴
