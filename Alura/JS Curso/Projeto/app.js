function renomearTextoDoCampo (tag, texto) {
    let campo = document.querySelector(tag);
    campo.innerHTML = texto;
}

let listaDeNumerosSorteados = [];
let level = 1;
let graudePrecisao = 0;

function aleatorizar(minTv, maxTv) {
    return parseInt(Math.random() * (maxTv - minTv + 1) + minTv);
}

function gerarNumAleatorio (min, max) {
    let minT = min < 0 ? min - 1 : min;
    let maxT = max < 0 ? max - 1 : max;

    let numeroSorteado = aleatorizar(minT, maxT);
    let quantidadeDeElementosNaLista = listaDeNumerosSorteados.length;

    if (quantidadeDeElementosNaLista == maxT - minT + 1) {
        listaDeNumerosSorteados = [];
    }

    if (listaDeNumerosSorteados.includes(numeroSorteado)) {
        numeroSorteado = gerarNumAleatorio(min, max);
    } else {
        listaDeNumerosSorteados.push(numeroSorteado);
        console.log(numeroSorteado);
    }
    return numeroSorteado;
}

function limparCampo(input) {
    input.value = '';
}

function tamanhoDeDigitos(valor) {
    let tamanhoDeDigitosFormula = parseInt(Math.log10(Math.abs(valor)) + 1);
    console.log("Tamanho do Valor (" + valor + ") é " + tamanhoDeDigitosFormula);
    return tamanhoDeDigitosFormula;
}

function preComparador (tamanhoDeDigitosMenor, tamanhoDeDigitosMaior, delta, valor) {    
    let tamanhoDeDigitosDelta = tamanhoDeDigitos(delta);
    let tamanhoDeDigitosValor = tamanhoDeDigitos(valor);
    console.log("A variação " + delta + " e o valor " + valor + " resulta em: " + Math.pow(10,(Math.max(Math.min(tamanhoDeDigitosDelta - tamanhoDeDigitosValor, tamanhoDeDigitosMaior - tamanhoDeDigitosValor + 1), Math.min(-tamanhoDeDigitosMaior + tamanhoDeDigitosValor - 1, tamanhoDeDigitosMenor)))));
    // return Math.pow(10,(Math.max(Math.min(tamanhoDeDigitosDelta - tamanhoDeDigitosValor, tamanhoDeDigitosMenor - tamanhoDeDigitosValor - 1),tamanhoDeDigitosValor - tamanhoDeDigitosMaior)));
    return Math.pow(10,(Math.max(Math.min(tamanhoDeDigitosDelta - tamanhoDeDigitosValor, tamanhoDeDigitosMaior - tamanhoDeDigitosValor + 1 ), Math.min(-tamanhoDeDigitosMaior + tamanhoDeDigitosValor - 1, tamanhoDeDigitosMenor))));
}

function comparador(deltaMax, deltaMin, valor, options) {
    let tamanhoDeDigitosMaior = tamanhoDeDigitos(deltaMax);
    let tamanhoDeDigitosMenor = tamanhoDeDigitos(deltaMin);
    let preComparadorMax = preComparador(tamanhoDeDigitosMenor, tamanhoDeDigitosMaior, deltaMax, valor);
    let preComparadorMin = preComparador(tamanhoDeDigitosMenor, tamanhoDeDigitosMaior,deltaMin, valor);

    console.log(deltaMax/preComparadorMax + " " + valor < preComparadorMin);

    let valorDeCorteMax = parseInt(deltaMax/preComparadorMax);
    let valorDeCorteMin = parseInt(deltaMin/preComparadorMin);

    console.log(valorDeCorteMax + " : " + deltaMax + " : " + preComparadorMax + " (MAX)");
    console.log(valorDeCorteMin + " : " + deltaMin + " : " + preComparadorMin + " (MIN)");

    switch (options) {
        case -1:
            return (valor > valorDeCorteMax && valor < valorDeCorteMin) || ((valorDeCorteMax > valorDeCorteMin) && (tamanhoDeDigitosMenor - tamanhoDeDigitosMaior == 0) ? (valor > valorDeCorteMax) || (valor < valorDeCorteMin) : false);
        
        case 1:
            return (valor < valorDeCorteMax && valor > valorDeCorteMin) || ((valorDeCorteMax < valorDeCorteMin) && (tamanhoDeDigitosMaior - tamanhoDeDigitosMenor == 0) ? (valor < valorDeCorteMax) || (valor > valorDeCorteMin) : false);   
        default:
            break;
    }    
}

function logisticModel(x, h, p, t, pm) {
    return p + (h - p) / (1 + Math.exp(-t * (x - pm)));
}

let hue = 210;
let lightMutilicador = 1; 
let variacao = 0;
let hueBorder = hue;

function espectativaParaEncontrar(min, max) {
    return (Math.sqrt(max - min + 1)*(3/4))
}

function alterarACor(alteracao, min, max) {
    let estimativaParaAchar = espectativaParaEncontrar(min, max);
    let limiarDeAtivação = Math.min((estimativaParaAchar + alteracao*0.1 - 6), 0)*0;
    variacao = (((((alteracao - 1 + limiarDeAtivação) / estimativaParaAchar))) * 100);
    hue = Math.round(logisticModel(variacao, 340, 210, 0.13, 52));
    hueBorder = Math.round(logisticModel(variacao, 355, 213, 0.08, 57));

    lightMutilicador = Math.round(logisticModel(variacao, 40, 100, 0.08, 90)) / 100;

    container.style.borderRadius = `${(logisticModel(variacao, 45, 24, 0.075, 72))}px`;
    container.style.border = `${(logisticModel(variacao, 20, 1, 0.075, 72))}px solid hsl(${hueBorder}, ${logisticModel(variacao, 100, 82, 0.1, 85)}%, ${logisticModel(variacao, 40, 50, 0.08, 100)}%)`;

    // Diminui a matiz em 10 graus a cada clique, movendo em direção ao vermelho
    if (hue < 0) { hue =+ 360; } // Reseta para 360 se passar de 0

    // document.body.style.background = `linear-gradient(hsl(${hue + 3}, 79%, ${36 * lightMutilicador}%) 0%, hsl(${hue + 4}, 85%, ${11 * lightMutilicador}%) 33.33%, hsl(${hue + 4}, 85%, ${11 * lightMutilicador}%) 66.67%, hsl(${hue - 2}, 87%, 3%) 100%)`;
    setGradient(document.body);
    mudarGradiente();
}

function setGradient (elemento) {
    elemento.style.background = `linear-gradient(hsl(${hue + 3}, 79%, ${36 * lightMutilicador}%) 0%, hsl(${hue + 4}, 85%, ${11 * lightMutilicador}%) 33.33%, hsl(${hue + 4}, 85%, ${11 * lightMutilicador}%) 66.67%, hsl(${hue - 2}, 87%, 3%) 100%)`;
}

// function logisticModel(x, h, p, t, pm) {
//     return p + (h - p) / (1 + Math.exp(-t * (x - pm)));
// }

// let hue = 210;
// let lightMultiplier = 1; 
// let variation = 0;

// function alterarACor(alteracao, min, max) {
//     variation = (((alteracao - 1) / (Math.sqrt(max - min + 1)*(3/4))) * 100);
//     hue = Math.round(logisticModel(variation, 340, 210, 0.13, 52));

//     lightMultiplier = Math.round(logisticModel(variation, 40, 100, 0.08, 90)) / 100;

//     // Atualiza as variáveis CSS com os novos valores
//     document.body.style.setProperty('--hue', hue.toString());
//     document.body.style.setProperty('--lightMultiplier', lightMultiplier.toString());
// }

function mudarGradiente() {
    
    // Alterna a opacidade dos gradientes para criar a transição
    if (gradient1.style.opacity === "1") {
        setGradient(gradient2);
        gradient2.style.opacity = "1";
        gradient3.style.opacity = "0";
        gradient1.style.opacity = "0";

    } else if (gradient2.style.opacity === "1") {
        setGradient(gradient3);
        gradient3.style.opacity = "1";
        gradient1.style.opacity = "0";
        gradient2.style.opacity = "0";
    } else {
        setGradient(gradient1);
        gradient1.style.opacity = "1";
        gradient2.style.opacity = "0";
        gradient3.style.opacity = "0";
    }
}

let numeroMinimo = 1;
let numeroMaximo = 5;
let numeroMaximoBase = numeroMaximo;
let inputUsuario = document.querySelector('input');
inputUsuario.min = numeroMinimo;
inputUsuario.max = numeroMaximo;
let historicoValue = inputUsuario.value;
let historicoChute = null;
let numeroSecreto = gerarNumAleatorio(numeroMinimo, numeroMaximo);
let tentativas = 0;

let gradient1 = document.getElementById('gradient1');
let gradient2 = document.getElementById('gradient2');
let gradient3 = document.getElementById('gradient3');
let container = document.getElementById('conteiner_1');

function renomearTitulo() {
    renomearTextoDoCampo('h1', 'Jogo do Número Secreto');
    renomearTextoDoCampo('p', `Escolha um número entre <strong>${numeroMinimo}</strong> e <strong>${numeroMaximo}</strong>`);
}

renomearTitulo();

console.log(Math.log10(Math.abs(-10))); 

inputUsuario.addEventListener('keyup', function(event){
    (event.key === "Enter") ? document.getElementById("chutar").click() : console.log("Tecla pessionada");
})
inputUsuario.addEventListener('input', function() {

    console.log(parseInt(this.value));

    console.log(this.value == '-');

    console.log(isNaN(this.value));

    console.log(this.value);

    // if (this.value > 0) {
    //     this.value > numeroMaximo;        
    // } else {
    //     let test2 = Math.pow(10,(tamanhoDeDigitos(numeroMaximo) - tamanhoDeDigitos(this.value)));
    //     console.log(this.value > numeroMaximo/(test2) && this.value < numeroMinimo/(test2));
    // }

    // if (this.value < 0) {
    //     this.value < numeroMinimo
    // } else {
    //     let test1 = Math.pow(10,(tamanhoDeDigitos(numeroMaximo) - tamanhoDeDigitos(this.value)));
    //     console.log(this.value < numeroMinimo/(test1) && this.value < numeroMaximo/(test1));
    // }
    
    if ((this.value > 0 ? this.value > numeroMaximo : comparador(numeroMaximo, numeroMinimo, this.value, -1)) || (this.value < 0 ? this.value < numeroMinimo : comparador(numeroMinimo, numeroMaximo, this.value, 1))) {
        let comparacaoValueMinMax = this.value > numeroMaximo ? 'máximo' : 'minimo';
        let comparacaoMostrarValorMinMax = this.value > numeroMaximo ? numeroMaximo : numeroMinimo;
        alert(`O valor ${comparacaoValueMinMax} permitido é ${comparacaoMostrarValorMinMax}`);
        this.value = historicoValue;
    }
    historicoValue = inputUsuario.value;
});



function alterarStatusDisabledByID(elemento, status) {
    switch (status) {
        case true:
            return document.getElementById(elemento).setAttribute('disabled', true);
        case false:
            return document.getElementById(elemento).removeAttribute('disabled');
        default:
            return document.getElementById(elemento).setAttribute('disabled', true);
    }
}
function alterarLavel(level,) {
    
}

function arrendondarPorMultiplo (number, multiplo, opition) {
    switch (opition) {
        case -1:
            return Math.floor(number/multiplo)*multiplo;

        case 1:
            return Math.ceil(number/multiplo)*multiplo;
        default:
            return Math.round(number/multiplo)*multiplo;
    }
    
}
let numeroBaseMaximoNovo = numeroMaximoBase;
let numerosNotaveis = 0;
let objetivoNotavel = 0;
function numeroNotavel(cLMF, mira) {
    return arrendondarPorMultiplo(cLMF, Math.pow(10, Math.floor(Math.log10(cLMF)) + objetivoNotavel), mira)
}

function gerarDifilculdadeNumMax(numeroMaximo) {
    let taxaPrimaria = logisticModel(level, 7, 57, 1.1, 4) - logisticModel(level, 7, 0.1, 0.12, 35);
    let calculoLevelMax = Math.round(((numeroMaximo + numeroBaseMaximoNovo*level*0.6)/(level*0.6 + 1)) * Math.pow(1 + (taxaPrimaria / 100), (level - 1)));
    calculoLevelMax = arrendondarPorMultiplo(calculoLevelMax, 5);
    let taxaAleatoriaPrimaria = arrendondarPorMultiplo((taxaPrimaria / 100)*numeroMaximo*0.50, 5);
    let taxaAleatoriaFinal = arrendondarPorMultiplo(aleatorizar(-taxaAleatoriaPrimaria*1.25,taxaAleatoriaPrimaria*0.75) * Math.min(Math.max(level, 5) - 5, 1), 5);
    let calculoLevelMaxFinal = calculoLevelMax + taxaAleatoriaFinal;
    level > 5 ? numeroBaseMaximoNovo = calculoLevelMaxFinal/(Math.pow(1 + (taxaPrimaria / 100), (level - 1))) : numeroBaseMaximoNovo = numeroMaximo;
    if (numerosNotaveis <= calculoLevelMaxFinal) {
        objetivoNotavel = 0;
        numerosNotaveis = numeroNotavel(calculoLevelMaxFinal, -1);
    }
    if ((numeroMaximo <= numerosNotaveis) && (calculoLevelMaxFinal >= numerosNotaveis) ) {
        calculoLevelMaxFinal = numerosNotaveis;
        objetivoNotavel = 1;
        numerosNotaveis = numeroNotavel(calculoLevelMaxFinal, 1);
    }
    return calculoLevelMaxFinal;
}

function reiniciarOJogo() {
    level++;
    alterarStatusDisabledByID('reiniciar', true);
    numeroMinimo = 1;
    numeroMaximo = gerarDifilculdadeNumMax(numeroMaximo);
    // inputUsuario = document.querySelector('input');
    inputUsuario.min = numeroMinimo;
    inputUsuario.max = numeroMaximo;
    historicoValue = null;
    historicoChute = null;
    numeroSecreto = gerarNumAleatorio(numeroMinimo, numeroMaximo);
    tentativas = 0;

    hue = 210;
    lightMutilicador = 1; 
    variacao = 0;
    hueBorder = hue;
    alterarACor(tentativas, numeroMinimo, numeroMaximo);

    renomearTitulo();

    limparCampo(inputUsuario);
    inputUsuario.type='number'
    inputUsuario.disabled = false;
    inputUsuario.placeholder = "Digite um número";

    alterarStatusDisabledByID('chutar', false);

    console.log(numeroSecreto);
    console.log("Level: " + level);
}

function verificarChute() {    
    
    let valueInputUsuario = inputUsuario.value;    

    console.log("O botão foi clicado!");
    console.log(`O número digitado foi ${valueInputUsuario}`);
    if (historicoChute != valueInputUsuario && inputUsuario.disabled == false) {
        if ((valueInputUsuario <= numeroMaximo) && (valueInputUsuario >= numeroMinimo)) {

            tentativas++;
            if (valueInputUsuario == numeroSecreto) {
                renomearTextoDoCampo('h1', 'Você Acertou!!!');
                renomearTextoDoCampo('p', '<strong>Parabéns!!!</strong> Você descobriu o número secreto!');
                inputUsuario.disabled = true;
                inputUsuario.type='text';
                let tentativasPlural = tentativas == 1 ? 'tentativa' : 'tentativas';
                inputUsuario.value = `O valor era ${numeroSecreto}, foi descoberto em ${tentativas} ${tentativasPlural}.`;
                alterarStatusDisabledByID('reiniciar', false);
                alterarStatusDisabledByID('chutar', true);
                graudePrecisao = tentativas/espectativaParaEncontrar(numeroMinimo, numeroMaximo);

            } else {
                let comparacao = valueInputUsuario < numeroSecreto ? "maior" : "menor";
                renomearTextoDoCampo('p', `O número secreto é <strong>${comparacao}</strong> que <strong>${valueInputUsuario}</strong>. \nEscolha novamente um número entre <strong>${numeroMinimo}</strong> e <strong>${numeroMaximo}</strong>`);
                // limparCampo(inputUsuario);
                alterarACor(tentativas, numeroMinimo, numeroMaximo);
            }
            
        } else {
            inputUsuario.placeholder = 'Valor anterior com intervalo incoreto';
            renomearTextoDoCampo('p', `Escolha novamente um número entre <strong>${numeroMinimo}</strong> e <strong>${numeroMaximo}</strong>`);
            limparCampo(inputUsuario);
        }
        historicoChute = valueInputUsuario;
    } else if (historicoChute == valueInputUsuario) {
        limparCampo(inputUsuario);
        console.log(`O número no histórico é ${historicoChute}`);
        // mudarGradiente();
    }

}

console.log(numeroSecreto);