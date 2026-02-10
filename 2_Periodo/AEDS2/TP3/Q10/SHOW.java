import java.io.*;
import java.nio.file.*;
import java.text.*;
import java.util.*;

public class SHOW {

    static final String MATRICULA = "854155";

    static class Show {
        String show_id, type, title, director, cast, country, date_added, rating, duration, listed_in;
        int release_year;

        Show(String[] fields) {
            this.show_id = !fields[0].isEmpty() ? fields[0] : "NaN";
            this.type = !fields[1].isEmpty() ? fields[1] : "NaN";
            this.title = !fields[2].isEmpty() ? fields[2] : "NaN";
            this.director = !fields[3].isEmpty() ? fields[3] : "NaN";
            this.cast = !fields[4].isEmpty() ? fields[4] : "NaN";
            this.country = !fields[5].isEmpty() ? fields[5] : "NaN";
            this.date_added = !fields[6].isEmpty() ? fields[6] : "NaN";
            this.release_year = !fields[7].isEmpty() ? Integer.parseInt(fields[7]) : -1;
            this.rating = !fields[8].isEmpty() ? fields[8] : "NaN";
            this.duration = !fields[9].isEmpty() ? fields[9] : "NaN";
            this.listed_in = !fields[10].isEmpty() ? fields[10] : "NaN";
        }

        void ordenarCast() {
            if (cast.equals("NaN")) return;
            String[] nomes = cast.split(",");
            for (int i = 0; i < nomes.length; i++) {
                nomes[i] = nomes[i].trim();
            }
            Arrays.sort(nomes, String.CASE_INSENSITIVE_ORDER);
            cast = String.join(", ", nomes);
        }

        Date parseDate() {
            if (date_added.equals("NaN")) return new Date(0);
            try {
                SimpleDateFormat sdf = new SimpleDateFormat("MMMM d, yyyy", Locale.ENGLISH);
                return sdf.parse(date_added);
            } catch (ParseException e) {
                return new Date(0);
            }
        }

        void print() {
            ordenarCast();
            System.out.printf("=> %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %d ## %s ## %s ## [%s] ##%n",
                show_id, title, type, director, cast, country, date_added, release_year, rating, duration, listed_in);
        }
    }

    static class Node {
        Show data;
        Node prev, next;
        Node(Show data) {
            this.data = data;
        }
    }

    static class DoublyLinkedList {
        Node head, tail;

        void addLast(Show data) {
            Node node = new Node(data);
            if (head == null) {
                head = tail = node;
            } else {
                tail.next = node;
                node.prev = tail;
                tail = node;
            }
        }

        Node last() {
            return tail;
        }
    }

    static class QuickSortList {
        long comparacoes = 0;

        int compareShows(Show a, Show b) {
            comparacoes++;
            int dateCmp = a.parseDate().compareTo(b.parseDate());
            if (dateCmp != 0) return dateCmp;
            return a.title.compareToIgnoreCase(b.title);
        }

        Node partition(Node low, Node high) {
            Show pivot = high.data;
            Node i = low.prev;

            for (Node j = low; j != high; j = j.next) {
                if (compareShows(j.data, pivot) <= 0) {
                    i = (i == null) ? low : i.next;
                    Show temp = i.data;
                    i.data = j.data;
                    j.data = temp;
                }
            }

            i = (i == null) ? low : i.next;
            Show temp = i.data;
            i.data = high.data;
            high.data = temp;

            return i;
        }

        void quickSort(Node low, Node high) {
            if (high != null && low != high && low != high.next) {
                Node p = partition(low, high);
                quickSort(low, p.prev);
                quickSort(p.next, high);
            }
        }
    }

    static String[] splitCSVLine(String line) {
        List<String> campos = new ArrayList<>();
        boolean dentroAspas = false;
        StringBuilder campo = new StringBuilder();

        for (int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);
            if (c == '"') {
                dentroAspas = !dentroAspas;
            } else if (c == ',' && !dentroAspas) {
                campos.add(campo.toString());
                campo = new StringBuilder();
            } else {
                campo.append(c);
            }
        }
        campos.add(campo.toString());
        return campos.toArray(new String[0]);
    }

    public static void main(String[] args) {
        List<Show> allShows = new ArrayList<>();
        try (BufferedReader br = Files.newBufferedReader(Paths.get("/tmp/disneyplus.csv"))) {
            br.readLine(); 
            String line;
            while ((line = br.readLine()) != null && allShows.size() < 1500) {
                String[] fields = splitCSVLine(line);
                if (fields.length < 11) continue;
                Show s = new Show(fields);
                allShows.add(s);
            }
        } catch (IOException e) {
            System.err.println("Erro ao ler arquivo CSV: " + e.getMessage());
            return;
        }

        DoublyLinkedList lista = new DoublyLinkedList();
        Scanner sc = new Scanner(System.in);

        while (true) {
            String input = sc.nextLine().trim();
            if (input.equals("FIM")) break;

            for (Show s : allShows) {
                if (s.show_id.equals(input)) {
                    lista.addLast(s);
                    break;
                }
            }
        }

        QuickSortList sorter = new QuickSortList();

        long startTime = System.currentTimeMillis();
        sorter.quickSort(lista.head, lista.tail);
        long endTime = System.currentTimeMillis();

        for (Node node = lista.head; node != null; node = node.next) {
            node.data.print();
        }

        try (PrintWriter log = new PrintWriter(MATRICULA + "_quicksort3.txt")) {
            log.printf("%s\t%d\t%d%n", MATRICULA, (endTime - startTime), sorter.comparacoes);
        } catch (IOException e) {
            System.err.println("Erro ao escrever arquivo de log: " + e.getMessage());
        }

        sc.close();
    }
}
