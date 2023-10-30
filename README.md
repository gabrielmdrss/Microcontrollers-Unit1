# Microcontroladores-Unidade1
 Atividade prática da unidade 1, foi usado o STM32F407.

### `01.` [Piscar um LED numa frequência de 2Hz, com largura de pulso de 250ms.](questoesPraticas/questao01.md)

### `02.` [Piscar um LED numa frequência de 0,5Hz, com largura de pulso de 100ms, produzindo um comportamento semelhante aos sinalizadores para aeronaves de baixa altitude no topo de edifícios.](questoesPraticas/questao02.md)

### `03.` [Piscar um LED com largura de pulso de 50ms, obedecendo o seguinte ciclo: pisca uma vez, aguarda um tempo e, em seguida, pisca duas vezes seguidas, aguardando mais um tempo.](questoesPraticas/questao03.md)

### `04.` [Piscar um LED com largura de pulso fica de 50ms, mas com frequência crescente, iniciando em 1Hz.](questoesPraticas/questao04.md)

### `05.` [Acionar um buzzer para emitir um som semelhante ao de um alarme sonoro: 4 beeps curtos de 50ms de largura, seguidos de uma pausa.](questoesPraticas/questao05.md)

### `06.` [Mostrar um LED aceso com diferentes intensidades de brilho, selecionadas em tempo de compilação, utilizando uma técnica de PWM por meio de software (utilize uma frequência PWM de 100Hz).](questoesPraticas/questao06.md)

### `07.` [Acender um LED com diferentes intensidades de brilho, alterando a intensidade em tempo de execução, utilizando uma técnica de PWM por meio de software (utilize uma frequência PWM de 100Hz). O LED deve iniciar apagado, aumentar gradativamente o brilho até o máximo e em seguida reduzir gradativamente o brilho até se apagar, repetindo o processo indefinidamente.](questoesPraticas/questao07.md)

### `08.` [Piscar dois LEDS, alternadamente, com largura de pulso de 50% do período, com frequência de 2Hz, produzindo um comportamento semelhante aos sinalizadores de saída de veículos em garagens. (Observação: verificar a simultaneidade de acionamento dos LEDs).](questoesPraticas/questao08.md)

### `09.` [Apresentar uma contagem binária de 2 bits a partir de 2 LEDs.](questoesPraticas/questao09.md)

### `10.` [Acender dois LEDs com diferentes intensidades de brilho, alterando alternadamente a intensidade em tempo de execução, semelhantemente ao que foi feito na questão 7.](questoesPraticas/questao10.md)

### `11.` [Apresentar uma contagem binária de 8 bits a partir de 8 LEDs externos. (obs.: para facilitar a implementação do código, conecte os LEDs a pinos contíguos de um mesmo GPIO).](questoesPraticas/questao11.md)

### `12.` [Implementar o efeito do LED andante nos 8 LEDs da questão anterior: ative o primeiro LED e faça com que o LED aceso se desloque do primeiro ao último, ou seja, se o primeiro está aceso, após um tempo apaga-se esse LED enquanto se acende o segundo, e assim sucessivamente até o oitavo LED. O LED andante deve se deslocar de um extremo a outro e em seguida fazer a operação no sentido inverso.](questoesPraticas/questao12.md)

### `13.` [Simular o funcionamento de um cruzamento com dois semáforos de trânsito usando 6 LEDs.](questoesPraticas/questao13.md)

### `14.` [Apresentar uma contagem decimal/hexadecimal (crescente e decrescente) de um dígito em um display de 7 segmentos.](questoesPraticas/questao14.md)

### `15.` [Apresentar uma contagem decimal/hexadecimal (crescente e decrescente) de dois dígitos em dois displays de 7 segmentos. (Obs: Utilize a técnica de multiplexação para usar a menor quantidade possível de terminais). Utilize transistores como drive de potência para fazer a comutação do sistema de multiplexação.](questoesPraticas/questao15.md)

### `17.` [Controlar um micro servomotor para que ele alterne suavemente a posição do eixo entre direita e esquerda, continuamente.](questoesPraticas/questao17.md)

### `18.` [Implementar o controle de velocidade de um motor DC para que ele acelere suavemente até sua velocidade máxima e em seguida desacelere e repita o mesmo procedimento no sentido contrário. Utilize uma ponte H como drive de potência para o motor.](questoesPraticas/questao18.md)

### `19.` [Realizar o acionamento de uma carga em corrente alternada (AC) de 220V a partir de um, relé.](questoesPraticas/questao19.md)

### `20.` [Realizar o acionamento de um motor de passo com velocidade e sentido variáveis considerando que o motor seja monopolar e, também, bipolar. Para cada caso, realize o acionamento através de passo completo, meio passo e micro passo. Quando o motor for monopolar, implemente um drive de potência com transistores. Quando o motor for bipolar, utilize duas pontes H como drive de potência ou utilize um drive de potência integrado](questoesPraticas/questao20.md)

### `21.` [Reproduzir em uma saída com um LED o estado de uma entrada com um push-button.](questoesPraticas/questao21.md)

### `22.` [Reproduzir em duas saídas com dois LEDs os estados de duas entradas com dois push-buttons.](questoesPraticas/questao22.md)

### `23.` [Utilizar uma entrada com um push-button para alternar o estado lógico de uma saída conectada a um LED.](questoesPraticas/questao23.md)

### `24.` [Utilizar dois push-button (K0 e K1) para acionar um LED com a seguinte regra: o LED só deve acender se o usuário pressionar os dois botões juntos, mas primeiro o botão K0 deve ser pressionado e só depois o botão K1.](questoesPraticas/questao24.md)

### `25.` [ Utilizar dois push-button (K0 e K1) para acionar um LED com a seguinte regra: o LED só deve acender se o usuário pressionar os dois botões juntos, mas primeiro o botão K0 e em seguida o botão K1. Se o botão K1 não for pressionado dentro de no máximo 1 segundo após K0 ser pressionado, o LED não deve acender.](questoesPraticas/questao25.md)