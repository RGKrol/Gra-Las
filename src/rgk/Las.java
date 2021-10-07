package rgk;

import org.junit.jupiter.api.Test;

// to jest biblioteka do robienia testów jednostkowych
import static org.junit.jupiter.api.Assertions.assertEquals;

public class Las {

    @Test
    void ICheckTheSelectionMethod (){
        assertEquals('m',Selection("","mki") );
        //assertEquals(1, 1); //nie wiem co sprawdzić - skoro ta metoda ma reagować na poczynania użytkownika ;-(
    }

    public static void Introduction (){
        System.out.println("Witaj w super trudnej i wymagającej grze \n");
        System.out.println("\t\t\t\tLAS\n");
        System.out.println("W grze zostajesz postaciom, która zgubiła się w lesie.");
        System.out.println("Twoje zadanie wydaje się tylko z pozoru łatwe:");
        System.out.println("\t\t--- Wróć do domu ---\n\n\n");
    }
    public static char Selection(String pytanie, String mozliweOdpowiedzi){
        while(true){
            System.out.println(pytanie);
            //nie wiem jak zapytać o odpowiedź wiec na razie założę odpowiedź
            String gamerAns = "m";

            if (gamerAns.length()!=1){
                System.out.println("Poproszę o odpowiedź w postaci jednej litery\n");
                continue;
            }

            for(char simpleAns : mozliweOdpowiedzi.toCharArray()){
                if(simpleAns == gamerAns.toCharArray()[0])
                    return gamerAns.toCharArray()[0];
            }
        }
    }
    public static void GenderSpecificText (char gender, String textToDisplay){
        // rozdzielenie tekstu na tablicę tak aby poszczególne puci były rozdzielone
        String [] t = textToDisplay.split("#");

        // wyłapuję interesujący mnie tekst w zależności od puci gracza
        for (String text : t){
            if (text.toCharArray()[0] == gender) {
                System.out.print(text.substring(1, text.length()));
                break;  //po co marnować czas skoro interesuje mnie jedna odpowiedź
            }
        }
    }

    public static void IntroductionForTheNewCharacter(char gender){

            GenderSpecificText(gender, "mObudziłeś się #kObudziłąś się #iBudzisz się ");
        System.out.println("w środku lasu. Pamiętasz to miejsce.");
        System.out.print("Dobrze się tu ");
            GenderSpecificText(gender, "mbawiłeś#kbawiłaś#ibawiłaś");
        System.out.println(" wczorajszej nocy. ");
        System.out.print("Ale dlaczego ");
            GenderSpecificText(gender, "mzasnąłeś?#kzasnełaś?#izmużył  oczy?");
        System.out.println(" i dlaczego ci idioci byli tak bezczelni, że nie zabrali Cię ze sobą?\n");

        System.out.println("No dobra, stało się. Trzeba wrócić do domu.");
        System.out.println("Więc gdzie jesteś?\n");

        System.out.println("Stoisz na leśnej polanie,");
        System.out.println("Po środku okrąg z kamieni, wewnątrz którego dogasa ognisko.");
        System.out.println("Trawa wydeptana, kilka kamieni i kłód drewna, które służyły za siedzenia.\n");
        System.out.println("Nigdzie nie widać butelek, puszek, papierków i temu podobnych,");
        System.out.println("no tak śmieci zabrali a o tobie zapominieli :-(\n");

        System.out.println("Ale którędy można stąd wyjść?\n...\n...\no jest !!!\n");

        /*  tu wejście do metody która pozwoli graczowi podjąć decyzję jak opuścić daną lokoację
            tu jest inne wywołanie metody decyzji gracza bo to startowa decyzja i gracz ma dwie możliwości
            "iść na wschód" lub "iść na zachód",
                        potem będzie tu możliwość zawrócenia lub przejścia przez tę polanę na wprost

            metoda przyjmuje:
            String  - opis możliwych wyjść z polany zależny od
                        --- być może z tego zrezygnuję gdyż opisy będą przechowywane gdzie indziej
                        --- docelowo teksty będą przechowywane w bazie danych
            int     - poprzednia pozycja gracza (skąd przyszedł)
            int     - aktualna pozycja gracza (gdzie doszedł)
            w zależności gdzie jest gracz i jak tam dotarł opisy będą różne !!!

            opis danej lokacji będzie stały ale
                opis możliwych wyjść będzie różny bo w końcu wchodzimy do lokacji z różnej strony
         */
    }

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// main /////////////////////////////
////////////////////////////////////////////////////////////////////////////////
    public static void main(String[] args) {
        Introduction();
        Postac player = new Postac();
        //wybór puci postaci oparty na uniwersalnej metodzie wyboru
        //nie wiem obecnie jak przekazać takie długie treści do metody i ładnie to przedstawić w kodzie
        //
        String textToDisplay = "Potrzebuję znać twoją płeć,\n";
                textToDisplay+="aby wiedzieć jak się do Ciebie zwracać.\n";
                textToDisplay+="Proszę wybierz (m) jeżeli jesteś mężczyzną, (k) jeżeli jesteś kobietą,\n";
                textToDisplay+="(i) jeżeli nie identyfikujesz się z pozostałymi wyborami";

        player.gender = Selection(textToDisplay, "mki");

        IntroductionForTheNewCharacter(player.gender);
        /*
            główna pętla gry
            tu gracz podejmuje decyzje którędy opuścić lokację doputy nie wybierze ścieszki prowadzącej nazewnątrz lasu

            opis metody w opisie powyższej metody
            te metody powstaną gdy nauczę się pobierać dane od gracza ;-)
         */
    }
}
