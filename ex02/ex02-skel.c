#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *next;
};
typedef struct node * NodePointer;

void listinitialize(void);
NodePointer insert(int key);
NodePointer delete(int key);
NodePointer finditem(int v);
void listprint(void);
NodePointer exchange(int v1, int v2);
void reverse(void);

NodePointer head, tail;

int main(){
  int i;

  /* �ꥹ�Ȥ����� */
  listinitialize();

  /* �ǡ����� 9 ���� 1 �ޤǥꥹ�Ȥ������ */
  for(i=9; i>=1; i--) {
    if( insert(i)==NULL ){
      printf("Data %d is already on the list\n",i);
    }
  }

  /* �ꥹ�Ȥ�ɽ�� */
  listprint();
  printf("\n");

  /* ���ꣲ */
  printf("=> exchange(1,2)\n");
  if( exchange(1,2)==NULL){
    printf("Cannot exchange\n");
  }
  listprint();
  printf("=> exchange(1,2)\n");
  if( exchange(1,2)==NULL){
    printf("Cannot exchange\n");
  }
  listprint();

  printf("=> exchange(4,7)\n");
  if( exchange(4,7)==NULL){
    printf("Cannot exchange\n");
  }
  listprint();
  printf("=> exchange(4,7)\n");
  if( exchange(4,7)==NULL){
    printf("Cannot exchange\n");
  }
  listprint();
  printf("\n");

  /* ���ꣳ */
  /* printf("=> reverse()\n"); */
  /* reverse();                */
  /* listprint();              */

  return 0;
}

/*
 * �ꥹ�Ȥν����
 * head �� tail ���äơ��Ҥ��롣
 */
void listinitialize(void){
  head = malloc(sizeof(struct node));
  tail = malloc(sizeof(struct node));

  head->next = tail;
  tail->next = tail;
}

/*
 * �������Ϥ��줿 key ��Ʊ���ͤΥΡ��ɤ����뤫��Ĵ�١�
 * ¸�ߤ��ʤ���С�key ���ͤ˻��ĥΡ��ɤ��ä� head �μ��˷Ҥ���
 * ���ΥΡ��ɤؤΥݥ��󥿤��֤���
 * ���Ǥ�¸�ߤ���ʤ�С��ꥹ�ȤˤϷҤ�����NULL ���֤���
 */
NodePointer insert(int key){
  NodePointer x;

  if(finditem(key) == NULL){
    /* key ���ͤ˻��ĥΡ��ɤ��� */
    x = malloc(sizeof(struct node));
    x->key = key;

    /* head �μ��˷Ҥ��� */
    x->next = head->next;
    head->next = x;
    return x;
  }
  return NULL;
}

/*
 * �������Ϥ��줿 key ��Ʊ���ͤΥΡ��ɤ����뤫��Ĵ�١�
 * ¸�ߤ���ʤ�С����ΥΡ��ɤ������롣
 * ¸�ߤ��ʤ���С��ꥹ�Ȥ����Ϥ��ʤ���
 * �֤��ͤ� finditem(key) ��Ʊ���ͤǤ��롣
 */
NodePointer delete(int key){
  NodePointer x, y;

  x = finditem(key);
  if(x != NULL){
    /* �������Ρ��ɤ������Ҥ������� */
    y = x->next;
    x->next = y->next;

    /* �Ρ��ɤ������� */
    free(y);
  }
  return x;
}

/*
 * head ���� tail �ޤǤΥΡ��ɤ���(key)��ɽ�����롣
 */
void listprint(void){
  NodePointer n;

  printf("Head - ");
  n = head->next;
  while (n != tail) {
    printf("%d - ", n->key);
    n = n->next;
  }
  printf("Tail\n");
}

/*
 * v ��Ʊ���ͤ���ĥΡ��ɤ�õ����
 * ���Ĥ���С����ΥΡ��ɤΤҤȤļ����ΥΡ��ɤؤΥݥ��󥿤��֤���
 * ���Ĥ���ʤ���С�NULL ���֤���
 */
NodePointer finditem(int v){
  NodePointer x, y;

  y = head;
  x = y->next;

  while(x != tail)
  {
    if(x->key == v){
      return y;
    }
    y = x;
    x = y->next;
  }
  return NULL;
}

/*
 * v1 ��Ʊ���ͤ����äƤ���Ρ��ɤ� v2 ��Ʊ���ͤ����äƤ���Ρ��ɤ�
 * �򴹤��롣
 * �򴹤Ǥ������ϡ�v1 ��Ʊ���ͤ����äƤ���Ρ��ɤؤΥݥ��󥿤��֤���
 * �򴹤Ǥ��ʤ����ϡ�NULL ���֤���
 */
NodePointer exchange(int v1, int v2){
  NodePointer p1, p2;
  NodePointer p3, p4, p5;

  p1=finditem(v1);
  p2=finditem(v2);
  if( p1==NULL || p2==NULL ){
    return NULL;
  }

  if( /* p2 �μ��� p1 �ʤ� */ ){
    /* �ݥ��� p1 �� p2 �������ؤ��� */
  }

  if( /* p1 �μ��� p2 �ʤ� */ ){

  }else{

  }

  return p1;
}

/*
 * �ꥹ�Ȥ�ս�˷Ҥ������롣
 */
void reverse(void){

}
