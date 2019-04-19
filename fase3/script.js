var args = process.argv.slice(2);

var n_pontos = args[0];
var raio = args[1];
var tempo = args[2];
var rotacao = 2*Math.PI/n_pontos;


console.log(`<translate Time=${tempo}/>`)

for(i=0;i<n_pontos;i++) {
  console.log(`<point X="${Math.cos(rotacao*i)*raio}" Y="0" Z="${Math.sin(rotacao*i)*raio}/>"`)
}
console.log(`</translate>`)
