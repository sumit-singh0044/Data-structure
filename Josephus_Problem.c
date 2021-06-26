#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int player;
    struct node *next;
    
};
struct node *head=NULL;
int main()
{
    int n,i,c,k;
    struct node *ptr , *temp , *traverse;
    printf("Enter the number of players:\t");
    scanf("%d",&n);
    printf("Enter the value of k (elimination index):\t");
    scanf("%d",&k);

    /*initializing the head of our node.*/

    head=(struct node*)malloc(sizeof(struct node));
    head->player=1;
    ptr=head;
    traverse=head;

/*creating our player node.*/
    for(i=2;i<=n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        ptr->next=temp;
        temp->player=i;
        temp->next=head;
        ptr=temp;
    }

    /*traversing our player id*/
    printf("Player id\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",traverse->player);
        traverse=traverse->next;
    }
    for(c=n;c>1;c--)
    {
        for(i=0;i<k-1;++i)
        {
            ptr=ptr->next;
        }
        ptr->next=ptr->next->next; /*eliminating player*/
    }
    printf("\n\nWinner is player %d \n\n",ptr->player);
    return 0;
}

