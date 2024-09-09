package main

import (
	"Ej6/src"
	"bufio"
	"errors"
	"fmt"
	"os"
	"time"
)

const (
	PROMPT = "\033[31m> \033[0m"
)

type Nodo[T any] struct {
	dato      T
	siguiente *Nodo[T]
}

type Cola[T any] struct {
	inicio, fin *Nodo[T]
}

func (c *Cola[T]) IsEmpty() bool {
	return c.inicio == nil
}

func (c *Cola[T]) Push(dato T) {
	var nueva = &Nodo[T]{dato, nil}

	if c.IsEmpty() {
		c.inicio = nueva
	} else {
		c.fin.siguiente = nueva
	}

	c.fin = nueva
}

func (c *Cola[T]) Pop() (T, error) {
	var dato T

	if c.IsEmpty() {
		return dato, errors.New("la cola esta vacia")
	}

	dato = c.inicio.dato
	c.inicio = c.inicio.siguiente

	return dato, nil
}

type Paciente struct {
	nombre string
	numero int
}

func (p *Paciente) String() string {
	return fmt.Sprintf("%s - %d", p.nombre, p.numero)
}

func mostrar(col *Cola[Paciente]) {
	var aux = &Cola[Paciente]{}
	var i = 1

	for !col.IsEmpty() {
		val, _ := col.Pop()
		aux.Push(val)
	}

	fmt.Println("Listado de pacientes:")
	for !aux.IsEmpty() {
		val, _ := aux.Pop()
		fmt.Printf("%d. %v\n", i, val)
		col.Push(val)
		i++
	}
}

func agregar(col *Cola[Paciente]) {
	var scanner = bufio.NewScanner(os.Stdin)
	var p = Paciente{}

	fmt.Println("Ingrese los datos del paciente")
	fmt.Print("    Nombre: ")
	scanner.Scan()
	p.nombre = scanner.Text()

	fmt.Print("    Numero: ")
	p.numero = src.Numero_validado(PROMPT)

	col.Push(p)
}

func atender(col *Cola[Paciente]) {
	if col.IsEmpty() {
		fmt.Println("No hay pacientes en la cola!")
		return
	}

	p, _ := col.Pop()
	fmt.Println("Atendiendo al paciente", p.nombre, "...")
	time.Sleep(3 * time.Second)
	fmt.Println("Paciente atendido")
}

func main() {
	var opciones = []func(col *Cola[Paciente]){
		mostrar,
		agregar,
		atender,
		func(col *Cola[Paciente]) { os.Exit(0) },
	}
	var opt int
	var cola = &Cola[Paciente]{}

	fmt.Println("\033[H\033[2J")
	for {
		fmt.Println("\n--- MENU ---")
		fmt.Println("1. Mostrar")
		fmt.Println("2. Agregar")
		fmt.Println("3. Atender")
		fmt.Println("4. Salir")

		opt = src.Numero_entre(1, len(opciones), PROMPT)
		fmt.Println("\033[H\033[2J")
		opciones[opt-1](cola)
	}
}
