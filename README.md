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

## BOSQUEJO E IMÁGENES AVANCE 1:
![image](https://github.com/user-attachments/assets/e8bbbb23-a671-42c6-8a4f-35a1670bac96)
![image](https://github.com/user-attachments/assets/7450f0f7-c12c-42ef-8026-837a8991bc73)
![image](https://github.com/user-attachments/assets/6e9888ed-db87-4a20-8332-cd00af7eb798)
![image](https://github.com/user-attachments/assets/109dac77-64e3-4ddb-883f-b5d90ae83ba4)
![image](https://github.com/user-attachments/assets/bfcf04b0-2b1b-4605-9e28-6d878ccb0ff1)
![image](https://github.com/user-attachments/assets/3ad54f91-e00a-445a-a5c3-a07b28a7a0de)
![image](https://github.com/user-attachments/assets/894e4221-9122-44ce-8461-b04a2dc0d2d7)
![image](https://github.com/user-attachments/assets/f1f2321a-0fce-45dd-b86f-6ec6c8633ddc)


## Video explicativo:
https://drive.google.com/drive/folders/1Fy-j_O2oXOxVf8DgTn-JzYnPky9xhUIK?usp=sharing
