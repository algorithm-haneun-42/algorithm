const fs = require("fs");
const path = require("path");

const inputFilePath = path.resolve(__dirname, "input.txt");
const input = fs.readFileSync(inputFilePath, "utf8").toString().split("\n");

const [n, d, k, c] = input[0].split(" ").map(e=>parseInt(e));
let sushi = [];
let check = Array(d+1).fill(0);
for(let i=1; i<=n; i++)
{
	sushi.push(parseInt(input[i]));
}

for(let i=0; i<k; i++)
{
	sushi.push(sushi[i]);
}
// let check = Array.from({length:d+1}, () => 0)
check[c] = 1;
let kind = 1;
for(let i=0; i<k; i++)
{
	if(check[sushi[i]] === 0 )
	{
		check[sushi[i]] = 1;
		kind++;
	}
	else
		check[sushi[i]]++;
}

let max = kind;

for(let i=k; i<sushi.length; i++)
{
	check[sushi[i]]++;
	if(check[sushi[i]] === 1 && check[sushi[i]] !== c)
	{
		kind++;

	}

	check[sushi[i - k]]--;
    if (check[sushi[i - k]] === 0) 
	{
        kind--;

	}

	max = Math.max(max, kind);

}


console.log(max);
