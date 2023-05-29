#retorna os subconjunto do conjunto n
def get_conjunto (n):
    #inicia um conjunto vazio
    conjunto = [[]]
    
    for num in n:
        #cria um novo subconjunto que inclui o numero
        new_conj = [conjut + [num] for conjut in conjunto]
        #adiciona o novo subconjunto a lista de subconjunto existente 
      conjunto.extend(new_conj)
    
    return conjunto
    
    
    print(get_conjunto([1,2]))