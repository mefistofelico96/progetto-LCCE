# progetto-LCCE
Progetto finale dell'esame di Laboratorio CAD di Circuiti Elettronici (LCCE) del Corso di Laurea in Ignegneria Elettronica dell'Università degli Studi di Napoli "Federico II" nell'A.A. 2018-2019.

## Partecipanti
Il progetto è stato realizzato dal gruppo formato da:
- Riccardo Avino;
- Marco Iacone;
- Alessandro Ilardi Garofalo;
- Adriana Ruotolo.

## Il codice
### Compilazione
Il seguente codice va compilato su [Mbed](https://os.mbed.com/) (deprecato) o [Keil](https://studio.keil.arm.com/auth/login) (consigliato) scegliendo come Build target la scheda NUCLEO-F401RE.

### Caricamento
Una volta completata la compilazione, il file `.bin` prodotto può essere caricato sulla scheda target opportunamente collegata al PC tramite USB.

### Librerie usate
Le librerie usate sono presenti su Mbed e state importate tramite Keil. Esse sono:
- [TEA5767](https://os.mbed.com/users/edodm85/code/TEA5767/): per gestire facilmente il modulo radio FM TEA5767;
- [TextLCD](https://os.mbed.com/users/simon/code/TextLCD/): per gestire facilmente lo schermo LCD.

## Clonare la repository del progetto su Keil
Per clonare la repository del progetto nel proprio workshop di Keil è necessario avere e collegare un account GitHub al proprio account Keil. Per eseguire la clonazione:
- cliccare su File -> Clone. Si aprirà una finestra;
- nella finestra aperta, inserire nella sezione URL il [link GitHub di questo progetto](https://github.com/mefistofelico96/progetto-LCCE) e nella sezione Project name indicare il nome che si desidera assegnare al progetto nel proprio workshop.

Una volta clonata la repository è possibile inviare e ricevere modifiche al codice in maniera semplice e senza dover copiare e incollare file.

## Gestione del codice
### Keil
La prima cosa da fare quando si apre questo progetto su Keil è controllare se c'è una richiesta di **_pull_**, così si ha il codice sempre aggiornato. Per eseguire un pull:
- cliccare sul simbolo di Source control nella barra verticale a sinistra (il simbolo è un branch);
- cliccare sui tre pallini e poi cliccare su Pull per eseguire una richiesta di pull dal master.

Una volta modificato il cdocie su Keil, bisogna eseguire un **_push_** per aggiornare il codice anche su GitHub. Per eseguire un push:
- cliccare sul simbolo di Source control nella barra verticale a sinistra;
- nella sezione sotto Message passare il mouse su Changes e cliccare sul "+" che compare accanto a Changes. In questo modo si organizzano tutte le modifiche effettuate a tutti i file del progetto
- scrivere nella sezione Message un messaggio relativo alle modifiche effettuate;
- cliccare sul simbolo della spunta sopra la sezione Message per eseguire il **_commit_**;
- cliccare sui tre pallini e poi cliccare su Push per eseguire un push su master. Va bene modificare solo il master.

### GitHub
Su GitHub le modifiche arrivano automaticamente se si lavora sul branch `master` (consigliato). Basta aggiornare la pagina per vederle.

Nota: quando si crea un progetto su Keil collegato a GitHub il branch principale viene automaticamente chiamato `master`. Cambiare nome a tale branch può causare problemi nella gestione delle richieste di pull e push.

## L'hardware
### Collegamento tra NUCLEO-F401RE e TEA5767
Il modulo radio FM TEA5767 usa il bus I2C per comunicare con l'esterno. Il pinout della scheda NUCLEO-F401RE è riportata di seguito:

![NUCLEO-F401RE pinout](https://github.com/mefistofelico96/progetto-LCCE/blob/master/readme_assets/NUCLEO-F401RE_pinout.png)

Si noti che il pin `D14` funge da SDA mentre il pin `D15` funge da SCL per il bus I2C1. Sono stati utilizzati tali pin per creare la comunicazione tra microcontrollore e modulo radio. Il collegamento va fatto collegando il pin SDA del modulo col pin SDA del microcontrollore e il pin SCL del modulo col pin SCL del microcontrollore. Il pinout del modulo radio FM TEA5767 è riportato di seguito:

![TEA5767 pinout](https://github.com/mefistofelico96/progetto-LCCE/blob/master/readme_assets/TEA5767_pinout.jpg)

Per quanto detto, il collegamento finale è riportato di seguito:

![Collegamento NUCLEO-TEA5767](https://github.com/mefistofelico96/progetto-LCCE/blob/master/readme_assets/collegamento_NUCLEO-TEA5767.png)

### Collegamento tra NUCLEO-F401RE e schermo LCD
Lo schermo LCD è stato collegato secondo quanto riportato di seguito:

![Collegamento NUCLEO-LCD](https://github.com/mefistofelico96/progetto-LCCE/blob/master/readme_assets/collegamento_NUCLEO-LCD.png)

### Pulsanti
Per controllare la frequenza attuale di ricezione sono stati utilizzati due pulsanti, uno che aumenta e un altro che riduce la frequenza corrente di un passo fisso pari a $0.25$ Hz. Tali pulsanti sono stati collegati ai pin `D7` e `D8` della scheda NUCLEO. Alla loro pressione essi riportano sui pin di lettura digitale della scheda uno `0` logico.

### Casse e amplificatore
Per rendere apprezzabile e gestibile l'audio in uscita al modulo radio è stato utilizzato semplicemente un amplificatore operazionale con resistore in retroazione variabile in modo da variare a piacimento il guadagno dello stadio.
