# DL-JS

**Interfaz Grafica No Oficial Para Youtube-DL**

*Status: Beta* :ballot_box_with_check:

AppVeyor [![Build status](https://ci.appveyor.com/api/projects/status/g905rwfg0n72cyfm?svg=true)](https://ci.appveyor.com/project/jackestar/dl-pj)



~~Travis~~

[Pagina Oficial](jackestar.netlify.com/indexDL) :globe_with_meridians:

## Descripción

Interfaz Grafica no oficial de QT para YoutubeDL, Descarga de [mas de 700 paginas diferentes](jackestar.netlify.app/list.html) En el formato y calidad que quieras, inicia sesión y baja tus videos de tu cuenta, o baja listas de reproducción incluso hasta canales completos.

Escrito en C++ usando el framework de QT, el motor de descarga YoutubeDL, FFmpeg y Wget se busca simplificar principalmente el gran motor de descarga que es YoutubeDL en toda su capacidad para todo usuario, Tratando de resolver la problematica de las paginas de descargas inseguras, limitativas y con publicidad trayendo una aplicacion de escritorio sencilla y para todo usuario.

**Compilación**

​	*Windows*

Con QT Creator (:heavy_check_mark:Testeado en 4.12.2) se selecciona el archivo proyecto "DL_JS_Lis.pro" se configura los compiladores (:heavy_check_mark:Testeado en MinGWin 4.3.4/GCC 7.2.0 32&64) y se compila en codigo. Luego se aplica Qt Deploy Tool (:heavy_check_mark:Testeado en 5.12.9) por consola, Eg.`windeployqt.exe --release --no-opengl-sw --no-system-d3d-compiler --no-translations DL-JS_Lis.exe` para añadir las librerias de qt requeridas y por ultimo se añade youtubeDL y FFmpeg junto al ejecutable.

Tambien se puede hacer manualmente con QMake

**Como Usar**

Toda la información de uso esta en la [pagina oficial del proyecto](jackestar.netlify.app/HowTo)

**Plataformas**

- Windows 7 (Con librerías incluidas)
- Linux (En desarollo)
- Mac (En desarrollo - Sin testeo a fondo)
- Android (Futuro Port)

**Traducciones**

*estado:* :ballot_box_with_check:Español	:white_check_mark:Español	:grey_question:Frances

​	*Windows*

En la carpeta "translations" se encuentran las traducciones actualemente hechas con la siguiente nomenclatura "DL-JS_lis_esp.qm" simplemente se copia la traducción deseada ala carpeta del ejecutable y se inicia. Hay otros aspectos que se preconfiguran sin necesidad de los archivos de traducción como el idioma de los subtitulos, etc.

Se ha de destacar que el programa esta hecho nativamente en español

De necesitar otra traducción se pueden crear con Qt Linguist (:heavy_check_mark:Testeado en 5.12.9) bajando el codigo de el repocitorio de [github](https://github.com/jackestar/Dl-PJ/) y creando una nueva traducción. Actualmente el desarrollo esta enfocado en alcanzar la estabilidad del programa, y automatizar procesos, mas se tiene de objetivo tene un alta cantidad de traducciones

**Caracteristicas**

:ballot_box_with_check:Descarga De Audio Video y Subtitulos

:ballot_box_with_check:Subtitulos Embedidos (Automatico en Crunchyroll)

:ballot_box_with_check:Login

:ballot_box_with_check:Descarga Listas de reproducción / Canales / Usuarios / Lista de Listas

:ballot_box_with_check:Multi lenguage (Ingles, Español, +)

:negative_squared_cross_mark:Actualizacion (FFMpeg - YoutubeDL - Core)

**Caracteristicas Futuras**

* Configurarcion para Proxies para youtubeDL y Wget (DL-Net)
* Ventana Escalable
* Eliminacion de la consola
* Modo debug/Vercion Debug
* AutoBuilds
* Adición de otro motor de descarga
* Mas Ports y Traducciones

**Requistos**

Windows 7 (Visual C++ Reidstibutable 2010 x86) 

**Copyright**

*Licencia*

Todo termino de licencia es abarcado por la **GNU GENERAL PUBLIC LICENSE**

Remarcando lo siguiente:

	Toda la obra esta libre de garantias y es de codigo fuente libre
	
	La descarga, instalación, ejecucion y uso de la obra estan libre de
	cualquier tipo de publicidad, pago o tipo de telemetria o estadistica
	
	Al usar codigo fuente, compilados del mismo o cualquier biblioteca en
	esta obra se esta inplicitamente aceptando los terminos y
	condiciones de esta obra y terceros, descritas en las licencias que
	invocan cada componente de esta obra

[Terceros]

UPx - Empequetador (https://upx.github.io)
FFMpeg - Motor de Multimedia [GNU - GPL v3]
QT - Framework [GNU - GPL v3] [Others Third Party Modules Licences]
Youtube-DL - Motor de Descargas [unlicense]
qdarkstyle - Tema de interfaz QT [MIT license]

Mas Detalles en [jackestar.netlify.app/Copyright](jackestar.netlify.app/Copyright)