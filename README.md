# Mecatrónica
## Dispensador de comida para gatos
Integrantes del Equipo:

David Ávila

Isidora Pinilla

Valentina Pizarro

Vicente Vergara

## Resumen del Proyecto:
Este proyecto tiene como objetivo diseñar y construir un dispensador automático de comida para gatos utilizando una placa Arduino y varios componentes electrónicos. El sistema está diseñado para mantener el plato del gato siempre abastecido con una cantidad óptima de comida, controlando tanto la cantidad como la frecuencia de la dispensación de forma automatizada. Los elementos principales del proyecto incluyen:

### Celda de Carga: 
La celda de carga se encarga de medir la cantidad de comida en el plato, asegurando que nunca falte o se sobrepase la cantidad de comida.

### Motor de Comida:
Un motor paso a paso, conectado a una hélice dispensadora, se encarga de mover la comida desde el contenedor hasta el plato del gato. El motor se activa en función del peso registrado por la celda de carga y de una frecuencia determinada por el usuario.

### Motor de Premio:
Un segundo motor controla un mecanismo que entrega premios al gato. Este motor realiza una vuelta completa para abrir un compartimiento que libera un premio, y luego se devuelve para cerrar dicho compartimiento.

### Buzzer:
Cuando el motor termina de funcionar, se activa un buzzer que reproduce una melodía breve para indicar que se ha terminado el proceso de dispensación.

### Control de Tiempo: 
El sistema también implementa un "tiempo de enfriamiento" determinado entre dispensaciones, asegurando que el dispensador no se active demasiadas veces.

## Lógica del Sistema:

Si el peso en el plato es menor al valor mínimo definido, se activa el motor de comida para dispensar hasta alcanzar el peso máximo.
Al mismo tiempo, se activa el motor de premio, abriendo y cerrando el compartimiento de premios.
El buzzer reproduce una melodía para indicar el termino de la dispensación.
Después de cada dispensación, el sistema entra en un estado de "enfriamiento" por x minutos/segundos antes de permitir otra dispensación, siempre y cuando el peso en el plato sea inferior al mínimo.
Tecnologías Utilizadas:
Arduino UNO: Controlador principal.
Motores Paso a Paso: Controlan el dispensador de comida y el compartimiento de premios.
Celda de Carga con Amplificador HX711: Para medir la cantidad de comida en el plato.
Buzzer: Indicador sonoro para el inicio de la dispensación.
