
#include<iostream>
#include<cmath>

using namespace std;
 
// Funções para Árvore Binária de Busca ---------------------------------------
 
typedef int KeyType;
typedef int ValueType;
 
struct DataType {
	KeyType key;
	ValueType value;
};
 
struct Node {
	DataType data;
	Node * right;
	Node * left;
} ;
 
 
void insert(Node *& curr, DataType data){	
	if(curr == NULL){
		curr = new Node;
		curr->data.value = data.value;
		curr->data.key = data.key;
		curr->right = NULL;
		curr->left = NULL;
	} else {
		if(data.value >= curr->data.value){
			insert(curr->right, data);
		} else if(data.value < curr->data.value) {
			insert(curr->left, data);
		}		
	}	
}
 
void show_ordered(Node * curr, int min, int max){
	if(curr->left != NULL)
		show_ordered(curr->left, min, max);
	if(curr->data.value >= min && curr->data.value <= max)
	    cout << curr->data.key << ":" << curr->data.value << endl;
	if(curr->right != NULL)
		show_ordered(curr->right, min, max);
}
 
void destruct(Node *& curr){
	if(curr->left != NULL)
		destruct(curr->left);
	if(curr->right != NULL)
	   	destruct(curr->right);
	delete curr;
	curr = NULL;
	return;
}
 
// ----------------------------------------------------------------------------
 
 
typedef struct {
	int x;
	int y;	
} Ponto;
 
double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}
 
// ----------------------------------------------------------------------------
 
int main()
{
    Ponto a, b, c, d;   //inserção struct pontos
    int alt, diam, esp, t, peso, min, max;  //entradas
    DataType data;         //struct pra torta
    Node * root = NULL;   //inserção árvore , começa vazia
    cin >> t;     //número de casos
    for(int i=0; i<t; i++){
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        cin >> c.x >> c.y;
        cin >> d.x >> d.y;
        cin >> peso;
        data.key = i;    //número torta
        alt = distancia(a,c);
        esp = distancia(a,b);
        diam = distancia(c,d);
        data.value = esp*peso*alt+diam+alt;
        insert(root, data);  //inserção na árovore
    }
    cin >> min >> max;
    show_ordered(root, min, max);  //ordena todos
    destruct(root);      //limpa árvóre
    return 0;
}
