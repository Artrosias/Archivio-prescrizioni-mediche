#include <stdio.h>
#include <stdlib.h>
#define BUFFERSIZE 300+1
struct medico{

    char id_medico[5];
    char nome_cognome[30];
    int anno_assunzione;
    int numero_prescrizioni;
    int eta;

}typedef struttura;

int conta (FILE*);
void carica (FILE* , struttura*);
void swap (struttura* , int);
void sort (int , struttura*);
void print (struttura* , int, int);


int main(void) {

  FILE *fp;
  struttura* medico;
  int n_prescrizioni = 0;
  fp = fopen("medici.txt", "r");
  int dim;


  if(fp == NULL){
    printf("errore nella lettura del file\n");
    return 1;
  }


  printf("inserire il numero di prescrizioni\n");
  scanf("%d", &n_prescrizioni);
  dim = conta(fp);
  medico = malloc(dim * sizeof(struttura));
  carica(fp, medico);
  fclose(fp);

  sort(dim, medico);
  print(medico, n_prescrizioni, dim);



  return 0;
}

int conta (FILE* fp) {

    char temp[BUFFERSIZE];
    int i = 0;

    while (!feof(fp)) {

        fgets (temp , BUFFERSIZE , fp);
        i++;
    }


    rewind (fp);
    return (i);
}


void carica (FILE* fp , struttura* medico) {

    int i = 0;
    while (!feof (fp)) {

        fscanf (fp , "%s %s %d %d %d" , medico[i].id_medico, medico[i].nome_cognome,&medico[i].anno_assunzione, &medico[i].numero_prescrizioni, &medico[i].eta);
        i++;
    }
}

void swap (struttura* prescrizioni , int j) {

    struttura temp = prescrizioni[j];
    prescrizioni[j] = prescrizioni[j+1];
    prescrizioni[j+1] = temp;

}


void sort (int dim , struttura* medico) {

    int flag=1 , i=0;

    while (flag==1) {

        flag=0;
        for (int j = 0; j < dim - i - 1; j++) {
            if (medico[j].eta > medico[j+1].eta) {
                swap (medico , j);
                flag = 1;

        }
        i++;
    }
  }
}




void print (struttura* medico , int min_prescrizioni, int dim) {

    for (int i = 0; i < dim; i++) {

        if (medico[i].numero_prescrizioni >= min_prescrizioni) {

            printf("%s %s %d %d %d\n" , medico[i].id_medico, medico[i].nome_cognome,medico[i].anno_assunzione, medico[i].numero_prescrizioni, medico[i].eta);
        }
    }

}
