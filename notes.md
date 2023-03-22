write
ft_printf y cualquier equivalente que TÚ hayas programado
signal
sigemptyset
sigaddset
sigaction
kill
getpid
malloc
free
pause
sleep
usleep
exit

- Debes crear un programa de comunicación en la forma de un cliente y un servidor.
- El servidor debe lanzarse primero, tras lanzarse debe mostrar su PID.
- El cliente tomará como parámetros:
	- El PID del servidor.
	- La string que debería mandarse.
	- El cliente debe comunicar la string pasada como parámetro al servidor. Una vez la string se haya recibido, el servidor debe mostrarla.
- El servidor debe ser capaz de mostrar la string suficientemente rápido.
	- Por rápido queremos decir que si piensas que es está tardando mucho, probablemente es que está tardando demasiado. 1 segundo para mostrar 100 caracteres es ¡muchíiiiisimo!
- Tu servidor debe poder recibir strings de distintos clientes consecutivamente, sin necesidad de reiniciar.
- La comunicación entre tu cliente y tu servidor debe hacerse SOLO utilizando señales UNIX.
