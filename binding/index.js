const binding = require('bindings')('winlose');




//JS implementation
const winloseImplementation = {
	add : (lhs1, lhs2) => lhs1 + lhs2,
}

const winloseNodeJS = new binding.NJSWinloseNodeJS(winloseImplementation);
console.log(winloseNodeJS)

const winlose = new binding.NJSWinlose(winloseNodeJS);

console.log(winlose) 
const result = winlose.callAdd(2, 5)
console.log(result)


const winloseVersion = winlose.getVersion()
console.log(winloseVersion)
//console.log(` Winlose version is >>>>>  ${winlose.getVersion()}  <<<<<`)