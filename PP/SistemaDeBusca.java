import javax.swing.JOptionPane;
public class SistemaDeBusca{
  public static void main(String[] args){
    Pessoa pessoas[] = new Pessoa[3];
    String nomePessoa = "";
    int resp = 0;
    for(int i = 0; i < 3; i ++){
      Pessoa pessoa = new Pessoa();
      String nome = JOptionPane.showInputDialog("Digite o nome da pessoa: " + (i + 1));
      pessoa.inserirNome(nome);
      pessoas[i] = pessoa;
    }
    nomePessoa = JOptionPane.showInputDialog("Digite o nome da pessoa a localizar: ");
    for(int i = 0; i < 3; i ++){
      if(nomePessoa.equals(pessoas[i].obterNome())){
        resp = 1;
        break;
      }
    }
    if(resp == 1){
      JOptionPane.showMessageDialog(null, "Usuario encontrado");
    }else{
      JOptionPane.showMessageDialog(null, "Usuario nao encontrado");
    }
  }
}
