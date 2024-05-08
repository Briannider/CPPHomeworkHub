## Corte de Control con Arreglos: Análisis de ventas por sucursal

**Problema:**

Se cuenta con un vector que contiene información sobre las ventas del mes de abril en una cadena de supermercados. Cada registro en el vector representa una venta individual y contiene datos sobre la sucursal, el día y el monto recaudado. El vector está agrupado por sucursal.

**Tareas:**

1. **Total de ventas por sucursal:**

   - Recorrer el vector agrupado por sucursal.
   - Para cada sucursal, calcular la suma de los montos recaudados en sus ventas.
   - Mostrar el total de ventas para cada sucursal.

2. **Día de mayor recaudación por sucursal:**

   - Recorrer el vector agrupado por sucursal.
   - Para cada sucursal:
     - Inicializar variables para almacenar el día de mayor recaudación y su monto correspondiente.
     - Recorrer las ventas de la sucursal.
       - Si el monto actual es mayor que el monto máximo registrado para la sucursal:
         - Actualizar las variables con el nuevo día y monto máximo.
     - Mostrar el día de mayor recaudación y su monto para cada sucursal.

3. **Sucursal con menor recaudación:**
   - Inicializar variables para almacenar la sucursal con menor recaudación y su monto total.
   - Recorrer el vector agrupado por sucursal.
     - Para cada sucursal:
       - Calcular la suma de los montos recaudados en sus ventas.
       - Si el total de ventas actual es menor que el total mínimo registrado:
         - Actualizar las variables con la nueva sucursal y su monto total mínimo.
   - Mostrar la sucursal con menor recaudación y su monto total.

## Corte de Control con Archivos: Consolidación de registros

**Problema:**

Se tienen cuatro archivos: "estudiantes.dat", "docentes.dat", "graduados.dat" y "nodocentes.dat". Cada archivo contiene información sobre el nombre y el legajo de cada integrante, sin orden específico. Se requiere crear un archivo consolidado llamado "consolidado.dat" que integre todos los registros de los cuatro archivos originales. El archivo consolidado debe contener información sobre el nombre, legajo y claustro de cada persona, y debe estar ordenado por legajo. Finalmente, se debe mostrar el contenido del archivo ordenado en pantalla.

**Tareas:**

1. **Lectura de archivos:**
   - Leer cada uno de los cuatro archivos originales ("estudiantes.dat", "docentes.dat", "graduados.dat" y "nodocentes.dat").
   - Extraer el nombre y legajo de cada registro en cada archivo.
