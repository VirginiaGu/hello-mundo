class ProductorConsumidor(object):
	def __init__(self):
		self._TIME = 300
		pila = Stack()
		randomno = Random()
		cont1 = 0
		cont2 = 0
		competencia = 0
		opc = 0 #imprimo el proceso ganador con opc y el turno #imprimo el buffer #uso el hilo para poder pausar el tiempo
		while cont1 < 20 or cont2 < 20 or not pila.empty():
			opc = randomno.nextInt(3)
			if opc == 0:
				if cont1 < 20 and pila.size() < 20:
					pila = ProductorConsumidor.Productor1(pila)
				cont1 += 1
			elif opc == 1:
				if cont2 < 20 and pila.size() < 20:
					pila = ProductorConsumidor.Productor2(pila)
				cont2 += 1
			elif opc == 2:
				pila = ProductorConsumidor.Consumidor(pila)
			print("\n\tProceso ganador: " + opc + "\tTurno: " + competencia)
			Console.WriteLine("\n\n\n\tElementos de la pila: " + pila)
			competencia += 1
			try:
				Thread.sleep(self._TIME)
			except Exception, e:
				Console.WriteLine("Fallo en el tiempo de pausado")
			finally: Console.WriteLine("Fallo en el tiempo de pausado")
def Productor1(Pila):
	randomno = Random()
	resultado = randomno.nextInt(26)
	resultado += 65
	letra = resultado
	Pila.push(letra)
	return Pila

Productor1 = staticmethod(Productor1)

def Productor2(pila):
	randomno = Random()
	resultado = randomno.nextInt(9)
	pila.push(resultado)
	return pila

Productor2 = staticmethod(Productor2)

def Consumidor(pila):
	if not pila.empty():
		pila.pop()
	return pila

Consumidor = staticmethod(Consumidor)
	
