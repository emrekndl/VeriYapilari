#ifndef bKutuphane
#define bKutuphane
struct n{
        int x;
        n * next;
};
typedef n node;
void bastir(node *);
node * ekleSirali(node *, int);
node * sil(node *,int);

#endif
