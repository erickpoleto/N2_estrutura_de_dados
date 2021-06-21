using System;
using System.Collections.Generic;

public class Pilha<T> {
    private List<T> pilha;

    public Pilha()
    {
        this.pilha = new List<T>();
    }

    public void push(T valor) 
    {
        this.pilha.Add(valor);
    }

    public void pop()
    {
        if(!this.isEmpty()) {
            this.pilha.RemoveAt(this.pilha.Count - 1);
            return;
        }
    }

    public void busca(T valor)
    {
        if(!this.pilha.Contains(valor)) {
            Console.WriteLine("Valor não encontrado");
            Console.WriteLine();
            return;
        } 
        for(int i = this.pilha.Count; i > 0; i--) {
            if(this.pilha[i-1].Equals(valor)) Console.WriteLine("Valor Encontrado: " + this.pilha[i-1]);
        }
    }

    public void imprime()
    {
        if(!this.isEmpty()) {
            for(int i = this.pilha.Count; i > 0; i--) Print(this.pilha[i-1]);
        }
        Console.WriteLine();
    }

    private bool isEmpty() 
    {
        if(this.pilha.Count > 0) {
            return false;
        }
        Console.WriteLine("A pilha está vazia");
        Console.WriteLine();
        return true;
    }

    private void Print(T val) 
    {
        Console.WriteLine(val);
    }
}