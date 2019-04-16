//tips:字典树
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
const int sonnum=26,base='a';
typedef struct trie
{
 int sum;/*某一路径对应的字符串的可能性(probability)*/
 char *let;/*某一路径对应的字符串存储在其末尾节点*/
 struct trie *son[sonnum];
}Trie;
Trie *maxx[100];/*前i个按键组合所对应的最大可能性字符串*/
int dmax[100];/*前i个按键组合所对应的最大可能性值*/
Trie *NewTrie()
{
 int i;
 Trie *temp=new Trie;
 temp->sum=0;
 for(i=0;i<sonnum;i++)
  temp->son[i]=NULL;
 return temp;
}
void Insert(Trie *pnt,char *s,int p)
{
 Trie *temp=pnt;
 int i,j;
 int len=strlen(s);
 char *tmp=NULL,str[2];
 for(i=0;i<len;i++)
 {
  j=s[i]-base;
  if(temp->son[j]==NULL)
  {
   temp->son[j]=NewTrie();
   temp->son[j]->let=new char[i+2];
   if(tmp!=NULL){
    strcpy(temp->son[j]->let,tmp);
    str[0]=s[i];str[1]='\0';
    strcat(temp->son[j]->let,str);
    temp->son[j]->let[i+1]='\0';
   }
   else
   {
    temp->son[j]->let[i]=s[i];
    temp->son[j]->let[i+1]='\0';
   }
  }
  temp->son[j]->sum+=p;
  tmp=new char[i+2];
  strcpy(tmp,temp->son[j]->let);
  tmp[i+1]='\0';
  temp=temp->son[j];
 }
 delete[] tmp;
}
void Delete(Trie *pnt)
{
 int i;
 if(pnt!=NULL)
 {
  for(i=0;i<sonnum;i++)
   if(pnt->son[i]!=NULL)
    Delete(pnt->son[i]);
  delete pnt;
  pnt=NULL;
 }
}
void Search(int dep,Trie *pnt,char *dec,int len)
{
 Trie *tmp;
 if(pnt->sum>dmax[dep])
 {
  dmax[dep]=pnt->sum;
  maxx[dep]=pnt;
 }
 dep++;
 if(dep>=len)
  return;
 if(dec[dep]=='2')
 {
  tmp=pnt->son['a'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['b'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['c'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
 }
 else if(dec[dep]=='3')
 {
  tmp=pnt->son['d'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['e'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['f'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
 }
 else if(dec[dep]=='4')
 {
  tmp=pnt->son['g'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['h'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['i'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
 }
 else if(dec[dep]=='5')
 {
  tmp=pnt->son['j'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['k'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['l'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
 }
 else if(dec[dep]=='6')
 {
  tmp=pnt->son['m'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['n'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['o'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
 }
 else if(dec[dep]=='7')
 {
  tmp=pnt->son['p'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['q'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['r'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['s'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
 }
 else if(dec[dep]=='8')
 {
  tmp=pnt->son['t'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['u'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['v'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
 }
 else
 {
  tmp=pnt->son['w'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['x'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['y'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
  tmp=pnt->son['z'-base];
  if(tmp)
   Search(dep,tmp,dec,len);
 }
}
int main()
{
 int i,scen,cases,w,p,m,len;
 char word[101],dec[102];
 Trie *root,*tmp;
 cases=1;
 scanf("%d",&scen);
 while(scen--)
 {
  root=NewTrie();
  scanf("%d",&w);
  while(w--)
  {
   scanf("%s",word);
   scanf("%d",&p);
   Insert(root,word,p);
  }
  printf("Scenario #%d:\n",cases++);
  scanf("%d",&m);
  while(m--)
  {
   scanf("%s",dec);
   len=strlen(dec)-1;
   for(i=0;i<100;i++)
    dmax[i]=0;
   if(dec[0]=='2')
   {
    tmp=root->son['a'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['b'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['c'-base];
    if(tmp)
     Search(0,tmp,dec,len);
   }
   else if(dec[0]=='3')
   {
    tmp=root->son['d'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['e'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['f'-base];
    if(tmp)
     Search(0,tmp,dec,len);
   }
   else if(dec[0]=='4')
   {
    tmp=root->son['g'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['h'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['i'-base];
    if(tmp)
     Search(0,tmp,dec,len);
   }
   else if(dec[0]=='5')
   {
    tmp=root->son['j'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['k'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['l'-base];
    if(tmp)
     Search(0,tmp,dec,len);
   }
   else if(dec[0]=='6')
   {
    tmp=root->son['m'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['n'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['o'-base];
    if(tmp)
     Search(0,tmp,dec,len);
   }
   else if(dec[0]=='7')
   {
    tmp=root->son['p'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['q'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['r'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['s'-base];
    if(tmp)
     Search(0,tmp,dec,len);
   }
   else if(dec[0]=='8')
   {
    tmp=root->son['t'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['u'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['v'-base];
    if(tmp)
     Search(0,tmp,dec,len);
   }
   else
   {
    tmp=root->son['w'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['x'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['y'-base];
    if(tmp)
     Search(0,tmp,dec,len);
    tmp=root->son['z'-base];
    if(tmp)
     Search(0,tmp,dec,len);
   }
   for(i=0;i<len;i++)
   {
    if(dmax[i]==0)
     printf("MANUALLY\n");
    else
     printf("%s\n",maxx[i]->let);
   }
   printf("\n");
  }
  printf("\n");
  Delete(root);
 }
}
//Accepted

