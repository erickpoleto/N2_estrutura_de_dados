using System;

namespace estrutura_de_dados
{
    class Program
    {
        static void Main(string[] args)
        {
            Pilha<int> pilha = new Pilha<int>();
            
            while (true) 
            {
                Console.WriteLine("--- Estrutura de dados ---");
                Console.WriteLine("--- Pilha ---");
                Console.WriteLine("1 - adicionar ao topo");
                Console.WriteLine("2 - remover do topo");
                Console.WriteLine("3 - buscar valor");
                Console.WriteLine("4 - imprimir pilha");
                Console.WriteLine("8 - Sair");
                Console.Write("Escolha uma das opções acima: ");
                switch(Convert.ToInt32(Console.ReadLine()))
                {
                    case 1:
                        Console.Write("valor: ");
                        pilha.push(Convert.ToInt32(Console.ReadLine()));
                        break;
                    case 2:
                        pilha.pop();
                        break;
                    case 3:
                        Console.WriteLine();
                        Console.Write("valor: ");
                        pilha.busca(Convert.ToInt32(Console.ReadLine()));
                        break;
                    case 4:
                        Console.WriteLine();
                        pilha.imprime();
                        break;
                    case 8:
                        System.Environment.Exit(0);
                        break;
                    default:
                        Console.WriteLine("Opção inválida");
                        break;
                }
            }
        }
    }
}
