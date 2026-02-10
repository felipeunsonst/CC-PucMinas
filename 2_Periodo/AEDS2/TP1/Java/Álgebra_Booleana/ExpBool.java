import java.util.Scanner;

public class ExpBool {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String entrada;

        do {
            entrada = scanner.nextLine();
            if(!saoIguais(entrada, "0"))
            {
                if(resolverEquacao(entrada)){
                    System.out.println("1");
                }else{
                    System.out.println("0");
                }
            }
        } while(!saoIguais(entrada, "0"));
        
        scanner.close();
    }

    public static String tratarExpressao(String entrada){
        String expressao;
        int n = entrada.charAt(0) - 48;

        expressao = removerEspacos(entrada);
        expressao = substituirTodos("and", 'e', expressao);
        expressao = substituirTodos("or" , 'o', expressao);
        expressao = substituirTodos("not", 'n', expressao);

        for(int i = 0; i < n; i++){
            char original = (char)('A' + i);
            char substituto = expressao.charAt(i + 1); 
            expressao = substituirTodos(original, substituto, expressao);
        }
        
        expressao = obterSubString(expressao, n + 1, expressao.length());
        return expressao;
    }

    public static String resolverExpressao(String entrada){
        int tamanho = entrada.length();
        char operacao = entrada.charAt(0);
        boolean resultado;
        switch(operacao) {
            case 'e':
                resultado = true;
                for(int i = 2; i < tamanho && resultado; i++){
                    if(entrada.charAt(i) == '0')
                    {
                        return "0";
                    }
                }
                return "1";
            case 'o':
                resultado = false;
                for(int i = 2; i < tamanho && !resultado; i++){
                    if(entrada.charAt(i) == '1')
                    {
                        return "1";
                    }
                }
                return "0";
            case 'n':
                return entrada.charAt(2) == '0' ? "1" : "0";
            default:
                return "";
        }
    }

    public static boolean resolverEquacao(String entrada){
        String expressao = tratarExpressao(entrada);
        while(expressao.contains("(")){
            int inicio = expressao.lastIndexOf('(');
            int fim = expressao.indexOf(')', inicio);
            
            String subExp = obterSubString(expressao, inicio - 1, fim + 1);            
            String resultado = resolverExpressao(subExp);
            expressao = obterSubString(expressao, 0, inicio - 1) + 
                        resultado + 
                        obterSubString(expressao, fim + 1, expressao.length());    
        }
        return saoIguais(expressao, "1");
    }

    public static boolean saoIguais(String str1, String str2){
        return str1.equals(str2);
    }

    public static String obterSubString(String s, int inicio, int fim){
        return s.substring(inicio, Math.min(fim, s.length()));
    }

    public static String removerEspacos(String entrada){
        return entrada.replaceAll("\\s+", "");
    }

    public static String substituirTodos(Object alvo, char novoChar, String entrada) {
        return entrada.replace(alvo.toString(), Character.toString(novoChar));
    }
}
