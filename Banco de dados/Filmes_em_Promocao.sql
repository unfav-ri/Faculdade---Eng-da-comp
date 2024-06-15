/*
 Antigamente a locadora fez um evento em que vários filmes estavam em promoção, queremos saber que filmes eram esses.
 
 Seu trabalho para nós ajudar é selecionar o ID e o nome dos filmes cujo preço for menor que 2.00.
 
 Esquema
 movies
 Coluna	            Tipo
 id (PK)	        numeric
 name	            varchar
 id_prices (FK)	    numeric  
 
 
 prices
 Coluna	        Tipo
 id (PK)	    numeric
 categorie	    varchar
 value	        umeric
 
 
 Tabelas
 movies
 id	name	                        id_prices
 1	Batman	                        3
 2	The Battle of the Dark River	3
 3	White Duck	                    5
 4	Breaking Barriers	            4
 5	The Two Hours	                2  
 
 
 prices
 id	categorie	    value
 1	Releases	    3.50
 2	Bronze Seal	    2.00
 3	Silver Seal	    2.50
 4	Gold Seal	    3.00
 5	Promotion	    1.50
 
 
 Exemplo de saída
 id	    name
 3	    White Duck
 */
/*
 Meu Resultado:
 */
SELECT
    m.id,
    m.name
FROM
    movies m
    JOIN prices p ON m.id_prices = p.id
WHERE
    p.value < 2.00
    AND p.categorie = 'Promotion';