#include <stdlib.h>
#include <stdio.h>

struct Aluno
{
    char nome_aluno[50];
    int numero_matricula;
};
struct Turma
{
    struct Aluno Estudantes[40];
    char Curso[20];
    int Codigo_da_Turma;
    int quantidade_alunos;
};

struct Turma Sala[10];
int quantidade_turma = 0;

void CadastrarTurma(char Curso[], int Codigo_da_Turma)
{
    Sala[quantidade_turma].quantidade_alunos = 0;
    strcpy(Sala[quantidade_turma].Curso, Curso);
    Sala[quantidade_turma].Codigo_da_Turma = Codigo_da_Turma;
    quantidade_turma++;
}

void CadastrarAluno(int Codigo_Turma, char Nome[], int Matricula)
{
    int i;
    for (i = 0; i < quantidade_turma; i++)
    {
        if (Codigo_Turma == Sala[i].Codigo_da_Turma)
        {
            strcpy(Sala[i].Estudantes[Sala[i].quantidade_alunos].nome_aluno, Nome);
            Sala[i].Estudantes[Sala[i].quantidade_alunos].numero_matricula = Matricula;
            Sala[i].quantidade_alunos++;
        }
    }
}

void VisualizarTurma(int Codigo_Turma)
{
    int i, j;
    for (i = 0; i < quantidade_turma; i++)
    {
        if (Codigo_Turma == Sala[i].Codigo_da_Turma)
        {
            printf("Turma: %s\n", Sala[i].Curso);
            for (j = 0; j < Sala[i].quantidade_alunos; j++)
            {
                printf("#%d Nome do aluno: %s Matricula: %d\n", j + 1, Sala[i].Estudantes[j].nome_aluno, Sala[i].Estudantes[j].numero_matricula);
            }
        }
    }
}
void RemoverAluno(int Codigo_Turma, int Numero_da_Matricula)
{
    int i, j;
    for (i = 0; i < quantidade_turma; i++)
    {
        if (Codigo_Turma == Sala[i].Codigo_da_Turma)
        {
            for (j = 0; j < Sala[i].quantidade_alunos; j++)
            {
                if (Sala[i].Estudantes[j].numero_matricula == Numero_da_Matricula)
                {
                    if (Sala[i].Estudantes[j].numero_matricula == Sala[i].Estudantes[Sala[i].quantidade_alunos - 1].numero_matricula)
                    {
                        Sala[i].Estudantes[j].numero_matricula = 0;
                        Sala[i].Estudantes[j].nome_aluno[0] = '\0';
                        Sala[i].quantidade_alunos = Sala[i].quantidade_alunos - 1;
                    }
                    else
                    {
                        for (j = j; j <= Sala[i].quantidade_alunos; j++)
                        {
                            Sala[i].Estudantes[j].numero_matricula = Sala[i].Estudantes[j + 1].numero_matricula;
                            strcpy(Sala[i].Estudantes[j].nome_aluno, Sala[i].Estudantes[j + 1].nome_aluno);
                        }
                        Sala[i].quantidade_alunos = Sala[i].quantidade_alunos - 1;
                    }
                }
            }
        }
    }
}

int main()
{

    int opcao, i, j, Numero_da_Matricula, Codigo_Turma;
    char Nome_do_Aluno[100], Turma[100];

    do
    {
        printf("-------------- ESCOLA BCC --------------\n\n");
        printf("1- ---------- Adicionar Aluno.\n");
        printf("2- ---------- Adicionar Turma.\n");
        printf("3- ---------- Visualizar Aluno.\n");
        printf("4- ---------- Visualizar Turma.\n");
        printf("5- ---------- Remover Aluno.\n");
        printf("6- ---------- Sair do menu.\n");
        printf("________________________________________\n");

        printf("\nEscolha uma opcao:\n");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("\nInforme o codigo da turma: \n");
            scanf("%d", &Codigo_Turma);
            printf("\nInforme o nome do aluno: \n");
            getchar();
            scanf(" %[^\n]s", Nome_do_Aluno);
            printf("\nInforme o numero da matricula: \n");
            scanf("%d", &Numero_da_Matricula);

            CadastrarAluno(Codigo_Turma, Nome_do_Aluno, Numero_da_Matricula);
        }
        else if (opcao == 2)
        {

            printf("\nInforme o nome da turma: \n");
            scanf("%s", Turma);
            printf("\nInforme o codigo da turma: \n");
            scanf("%d", &Codigo_Turma);

            CadastrarTurma(Turma, Codigo_Turma);
        }

        else if (opcao == 3)
        {
            printf("Informe o codigo da turma: \n");
            scanf("%d", &Codigo_Turma);

            for (i = 0; i < quantidade_turma; i++)
            {
                if (Codigo_Turma == Sala[i].Codigo_da_Turma)
                {
                    printf("Informe o numero da matricula: \n");
                    scanf("%d", &Numero_da_Matricula);
                    for (j = 0; j < Sala[i].quantidade_alunos; j++)
                    {
                        if (Sala[i].Estudantes[j].numero_matricula == Numero_da_Matricula)
                        {
                            printf("\n________________________");
                            printf("Dados do aluno: \n\n");
                            printf("Nome do aluno: %s\n", Sala[i].Estudantes[j].nome_aluno);
                            printf("Numero da matricula: %d\n", Sala[i].Estudantes[j].numero_matricula);
                            printf("Nome da turma: %s\n", Sala[i].Curso);
                            printf("Codigo da turma: %d\n", Sala[i].Codigo_da_Turma);
                            printf("\n________________________\n");
                        }
                    }
                }
            }
        }
        else if (opcao == 4)
        {
            printf("Turmas disponiveis: \n");
            for (i = 0; i < quantidade_turma; i++)
            {
                printf("Codigo da turma: #%d Nome da Turma: %s\n", Sala[i].Codigo_da_Turma, Sala[i].Curso);
            }

            printf("Informe o codigo da turma: \n");
            scanf("%d", &Codigo_Turma);

            VisualizarTurma(Codigo_Turma);
        }
        else if (opcao == 5)
        {
            printf("Informe o codigo da Turma: \n");
            scanf("%d", &Codigo_Turma);
            VisualizarTurma(Codigo_Turma);

            printf("Informe o numero da matricula do aluno que deseja remover:\n");
            scanf("%d", &Numero_da_Matricula);
            RemoverAluno(Codigo_Turma, Numero_da_Matricula);
        }
        system("pause");
        system("cls");
    } while (opcao != 6);

    printf("_____________________________________________\n");
    printf("----------- DESENVOLVEDORES -----------\n");
    printf("ANDREW LOPES LEAL\n");
    printf("ERIK CESAR DE QUEIROZ BRASIL\n");
    printf("IURY MIKAEL SOBRAL DOS SANTOS\n");
    printf("HENRIQUE DE ALMEIDA SILVA\n");
    printf("JOAO GUILHERME BENJAMIN ALVES DE REZENDE\n");
    printf("ROBERT FREIRE DE MELO\n");
    printf("WILLIAM BATISTA COUTO DOS SANTOS\n\n\n");
    printf("Se voce entender esse codigo, nos comunique! nem nos sabemos oque se passa aqui.\n");
    printf("Feito em 12 de Abril de 2022, as 01:15.\n");
    printf("\n_____________________________________________\n");




    system("pause");
    return 0;
}