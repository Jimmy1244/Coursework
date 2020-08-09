const infSent1 = document.getElementById('infSent1');
const infSent2 = document.getElementById('infSent2');
const infRuleID1 = document.getElementById('infRuleID1');
const infRuleID2 = document.getElementById('infRuleID2');
const infAdd = document.getElementById('infAdd');
const infRules = document.getElementById('infRules');
const infOutput = document.getElementById('infOutput');

const rplSent = document.getElementById('rplSent');
const rplRuleID = document.getElementById('rplRuleID');
const rplAdd1 = document.getElementById('rplAdd1');
const rplAdd2 = document.getElementById('rplAdd2');
const rplAdd3 = document.getElementById('rplAdd3');
const rplRules = document.getElementById('rplRules');
const rplOutput = document.getElementById('rplOutput');

const premiseList = document.getElementById('premiseList');


const buttonAnd = document.getElementById('buttonAnd');
const buttonOr = document.getElementById('buttonOr');
const buttonImply = document.getElementById('buttonImply');
const buttonEquiv = document.getElementById('buttonEquiv');
const buttonNot = document.getElementById('buttonNot');
const buttonAddPremise = document.getElementById('buttonAddPremise');
const buttonStartProve = document.getElementById('buttonStartProve');
const infAddButton = document.getElementById('infAddButton');
const rplAddButton = document.getElementById('rplAddButton');

var infType1Name = ["MP", "MT", "Res", "DS", "Simp", "HS", "CD"]
var infType1Op = [String.fromCharCode(8594), String.fromCharCode(8594), String.fromCharCode(8744), String.fromCharCode(8744), String.fromCharCode(8743), String.fromCharCode(8594), String.fromCharCode(8744)]

function indexOfArray(myArr, name) {
	var i;
	for (i = 0; i < myArr.length; i++) {
		if (name == myArr[i]) {
			return i;
		}
	}
	return -1;
}

function parseLogicSent(tuple, sent) {
	var len = sent.length;
	var i; var count = 1;
	if (sent[0] !=  "(") count = 0;
	for (i = 1; i < len && count > 0; i++) { 
		if (sent[i] == "(") count++;
		if (sent[i] == ")") count--;
	}
	tuple.part1 = sent.slice(1, i - 1);
	tuple.part2 = sent[i]; i++;
	tuple.part3 = sent.slice(i + 1, len - 1);
}

function replacement() {
	rplOutput.textContent = "";
	rplAddButton.disabled = true;
	var rplCode = rplRules.value.split('_');
	if (rplSent.textContent == "") {
		rplOutput.textContent = "ERROR: you should assign Sent";
		return;
	}
	if (rplAdd1.value == "") {
		rplOutput.textContent = "ERROR: you should assign p-part";
		return;
	}
	if ((indexOfArray(rplTypeName2, rplCode[0]) >= 0 || indexOfArray(rplTypeName3, rplCode[0]) >= 0) && rplAdd2.value == "") {
		rplOutput.textContent = "ERROR: you should assign q-part";
		return;
	}
	if (indexOfArray(rplTypeName3, rplCode[0]) >= 0 && rplAdd3.value == "") {
		rplOutput.textContent = "ERROR: you should assign r-part";
		return;
	}
	var oldPart = "";
	var oldPartPR = "";
	var newPart = "";
	var newPartPR = "";
	var newSent = "";
	var mainOp = String.fromCharCode(8743);
	var sndOp = String.fromCharCode(8744);
	if (rplCode[1] == 2) {
		mainOp = String.fromCharCode(8744);
		sndOp = String.fromCharCode(8743);
	}
	
	if (rplCode[0] == "DN") {
		oldPart = String.fromCharCode(172) + "(" + String.fromCharCode(172) + "(" + rplAdd1.value + ")" + ")";
		newPart = rplAdd1.value;
	}
	else if (rplCode[0] == "Comm") {
		oldPart = "(" + rplAdd1.value + ")" + mainOp + "(" + rplAdd2.value + ")";
		newPart = "(" + rplAdd2.value + ")" + mainOp + "(" + rplAdd1.value + ")";
	}
	else if (rplCode[0] == "Assoc") {
		oldPart = "((" + rplAdd1.value + ")" + mainOp + "(" + rplAdd2.value + "))" + mainOp + "(" + rplAdd3.value + ")";
		newPart = "(" + rplAdd1.value + ")" + mainOp + "((" + rplAdd2.value + ")" + mainOp + "(" + rplAdd3.value + "))";
	}
	else if (rplCode[0] == "Dist") {
		oldPart = "(" + rplAdd1.value + ")" + mainOp + "((" + rplAdd2.value + ")" + sndOp + "(" + rplAdd3.value + "))";
		newPart = "((" + rplAdd1.value + ")" + mainOp + "(" + rplAdd2.value + "))" +sndOp + "((" + rplAdd1.value + ")" + mainOp + "(" + rplAdd3.value + "))";
	}
	else if (rplCode[0] == "DeM") {
		oldPart = String.fromCharCode(172) + "((" + rplAdd1.value + ")" + mainOp + "(" + rplAdd2.value + "))";
		newPart = "(" + String.fromCharCode(172) + "(" + rplAdd1.value + "))" + sndOp + "(" + String.fromCharCode(172) + "(" + rplAdd2.value + "))";
	}
	else if (rplCode[0] == "Impl") {
		oldPart = "(" + rplAdd1.value + ")" + String.fromCharCode(8594) + "(" + rplAdd2.value + ")";
		newPart = "(" + String.fromCharCode(172) + "(" + rplAdd1.value + "))" + String.fromCharCode(8744) + "(" + rplAdd2.value + ")";
	}
	else if (rplCode[0] == "Contra") {
		oldPart = "(" + rplAdd1.value + ")" + String.fromCharCode(8594) + "(" + rplAdd2.value + ")";
		newPart = "(" + String.fromCharCode(172) + "(" + rplAdd2.value + "))" + String.fromCharCode(8594) + "(" + String.fromCharCode(172) + "(" + rplAdd1.value + "))";
	}
	else if (rplCode[0] == "Equiv") {
		oldPart = "(" + rplAdd1.value + ")" + String.fromCharCode(8596) + "(" + rplAdd2.value + ")";
		if (rplCode[1] == 1) {
			newPart = "((" + rplAdd1.value + ")" + String.fromCharCode(8594) + "(" + rplAdd2.value + "))" + String.fromCharCode(8743) + "((" + rplAdd2.value + ")" + String.fromCharCode(8594) + "(" + rplAdd1.value + "))";
		}
		else {
			newPart = "((" + rplAdd1.value + ")" + String.fromCharCode(8743) + "(" + rplAdd2.value + "))" + String.fromCharCode(8744) + "(" + String.fromCharCode(172) + "(" + rplAdd1.value + "))" + String.fromCharCode(8743) + "(" + String.fromCharCode(172) + "(" + rplAdd2.value + "))";
		}
	}
	else if (rplCode[0] == "Exp") {
		oldPart = "((" + rplAdd1.value + ")" + String.fromCharCode(8743) + "(" + rplAdd2.value + "))" + String.fromCharCode(8594) + "(" + rplAdd3.value + ")";
		newPart = "(" + rplAdd1.value + ")" + String.fromCharCode(8594) + "((" + rplAdd2.value + ")" + String.fromCharCode(8594) + "(" + rplAdd3.value + "))";
	}
	else if (rplCode[0] == "Idem") {
		oldPart = "(" + rplAdd1.value + ")" + mainOp + "(" + rplAdd1.value + ")";
		newPart = rplAdd1.value;
	}
	else if (rplCode[0] == "Abs") {
		oldPart = "(" + rplAdd1.value + ")" + mainOp + "((" + rplAdd1.value + ")" + sndOp + "(" + rplAdd2.value + "))";
		newPart = rplAdd1.value;
	}
	
	if (rplCode[2] == 2) {
		var tmp = oldPart;
		oldPart = newPart;
		newPart = tmp;
	}
	oldPartPR = "(" + oldPart + ")";
	newPartPR = "(" + newPart + ")";
	var offset = rplSent.textContent.indexOf(oldPartPR);
	if (offset < 0 && oldPart != rplSent.textContent) {
		rplOutput.textContent = "ERROR: the string [" + oldPart + "] does not appear in Sent";
	}
	else {
		if (offset >= 0) {
			newSent = rplSent.textContent.slice(0, offset) + newPartPR + rplSent.textContent.slice(offset + oldPartPR.length, rplSent.textContent.length);
		}
		else {
			newSent = newPart;
		}
		rplOutput.textContent = newSent;
		rplAddButton.disabled = false;
	}
}

var rplTypeName2 = ["Comm", "DeM", "Impl", "Contra", "Equiv", "Abs"]
var rplTypeName3 = ["Assoc", "Dist", "Exp"]
function rplCheckElementShow() {
	//alert('yea');
	document.getElementById('rplAddLabe2').style.display = "none";
	document.getElementById('rplAddLabe3').style.display = "none";
	rplAdd2.style.display = "none";
	rplAdd3.style.display = "none";
	var rplCode = rplRules.value.split('_');
	if (indexOfArray(rplTypeName2, rplCode[0]) >= 0) {
		document.getElementById('rplAddLabe2').style.display = "inline";
		rplAdd2.style.display = "inline";
	}
	else if (indexOfArray(rplTypeName3, rplCode[0]) >= 0) {
		document.getElementById('rplAddLabe2').style.display = "inline";
		document.getElementById('rplAddLabe3').style.display = "inline";
		rplAdd2.style.display = "inline";
		rplAdd3.style.display = "inline";
	}
}

function infCheckElementShow() {
	//alert('yea');
	var nowLabel = document.getElementById('infAddLabel');
	nowLabel.style.display = "none";
	infAdd.style.display = "none";
	var infCode = infRules.value;
	if (infCode == "Add") {
		nowLabel.style.display = "inline";
		infAdd.style.display = "inline";
	}
}

function inference() {
	infOutput.textContent = "";
	infAddButton.disabled = true;
	var infCode = infRules.value;
	if (infSent1.textContent == "") {
		infOutput.textContent = "ERROR: you should assign Sent1";
		return;
	}
	if (infCode != "Add" && infSent2.textContent == "") {
		infOutput.textContent = "ERROR: you should assign Sent2";
		return;
	}
	var sentLeft1 = infSent1.textContent;
	var sentOp1 = "whole";
	var sentRight1 = "";
	var infIndex = indexOfArray(infType1Name, infCode);
	if (infCode == "Conj") {
		infOutput.textContent = "(" + infSent1.textContent + ")" + String.fromCharCode(8743) + "(" + infSent2.textContent + ")";
		infAddButton.disabled = false;
	}
	else if (infCode == "Add") {
		infOutput.textContent = "(" + infSent1.textContent + ")" + String.fromCharCode(8744) + "(" + infAdd.value + ")";
		infAddButton.disabled = false;
	}
	else if(infIndex >= 0) {
		var myTuple = {part1: "1", part2: "2", part3: "3"};
		parseLogicSent(myTuple, infSent1.textContent);
		sentLeft1 = myTuple.part1;
		sentOp1 = myTuple.part2;
		sentRight1 = myTuple.part3;
		
		if (sentOp1 != infType1Op[infIndex]) {
			infOutput.textContent = "ERROR: Sent1 is not in the form of p" + infType1Op[infIndex] + "q";
		}
		else {
			if (infCode == "Simp") {
				infOutput.textContent = sentLeft1;
				infAddButton.disabled = false;
			}
			else if (infCode == "MP") {
				if (sentLeft1 != infSent2.textContent) {
					infOutput.textContent = "ERROR: Sent2 [" + infSent2.textContent + "] does not match the p-part [" + sentLeft1 + "] in Sent1";
				}
				else {
					infOutput.textContent = sentRight1;
					infAddButton.disabled = false;
				}
			}
			else if (infCode == "MT" || infCode == "DS") {
				if (infSent2.textContent[0] != String.fromCharCode(172)) {
					infOutput.textContent = "ERROR: Sent2 [" + infSent2.textContent + "] is not a negation";
				}
				else {
					var insideStr = infSent2.textContent.slice(2, infSent2.textContent.length - 1);
					if (sentRight1 != insideStr) {
						infOutput.textContent = "ERROR: Sent2 [" + insideStr + "] does not match the q-part [" + sentRight1 + "] in Sent1";
					}
					else {
						if (infCode == "MT") {
							infOutput.textContent = String.fromCharCode(172) + "(" + sentLeft1 + ")";
						}
						if (infCode == "DS") {
							infOutput.textContent = sentLeft1;
						}
						infAddButton.disabled = false;
					}
				}
			}
			if (infCode == "Res" || infCode == "HS") {
				var needOP = infType1Op[infIndex];
				parseLogicSent(myTuple, infSent2.textContent);
				var sentLeft2 = myTuple.part1;
				var sentOp2 = myTuple.part2;
				var sentRight2 = myTuple.part3;
				var formatStr = "p" + needOP + "r";
				if (infCode == "Res") {
					formatStr = String.fromCharCode(172) + formatStr;
				}
				
				if (sentOp2 != needOP || (infCode == "Res" && sentLeft2[0] != String.fromCharCode(172))) {
					infOutput.textContent = "ERROR: Sent2 is not in the form of " + formatStr;
				}
				else if (infCode == "Res") {
					var insideStr = sentLeft2.slice(2, sentLeft2.length - 1);
					if (sentLeft1 != insideStr) {
						infOutput.textContent = "ERROR: The p-part in Sent2 [" + insideStr + "] does not match the p-part [" + sentLeft1 + "] in Sent1";
					}
					else {
						infOutput.textContent = "(" + sentRight1 + ")" + String.fromCharCode(8744) + "(" + sentRight2 + ")";
						infAddButton.disabled = false;
					}
				}
				else if (infCode == "HS") {
					if (sentRight1 != sentLeft2) {
						infOutput.textContent = "ERROR: The p-part in Sent2 [" + insideStr + "] does not match the q-part [" + sentLeft1 + "] in Sent1";
					}
					else {
						infOutput.textContent = "(" + sentLeft1 + ")" + String.fromCharCode(8594) + "(" + sentRight2 + ")";
						infAddButton.disabled = false;
					}
				}
			}
			if (infCode == "CD") {
				parseLogicSent(myTuple, sentLeft1);
				var pStr = myTuple.part1;
				var innerOp1 = myTuple.part2;
				var qStr = myTuple.part3;
				parseLogicSent(myTuple, sentRight1);
				var rStr = myTuple.part1;
				var innerOp2 = myTuple.part2;
				var sStr = myTuple.part3;
				parseLogicSent(myTuple, infSent2.textContent);
				var pStr2 = myTuple.part1;
				var sentOp2 = myTuple.part2;
				var rStr2 = myTuple.part3;
				if (sentOp2 != String.fromCharCode(8744)) {
					infOutput.textContent = "ERROR: Sent2 is not in the form of p" + String.fromCharCode(8744) + "r";
				}
				else if (innerOp1 != String.fromCharCode(8594) || innerOp2 != String.fromCharCode(8594)) {
					infOutput.textContent = "ERROR: inner sentence in Sent1 is not in the form of p" + String.fromCharCode(8744) + "q";
				}
				else if (pStr != pStr2) {
					infOutput.textContent = "ERROR: The p-part in Sent2 [" + pStr2 + "] does not match the p-part [" + pStr + "] in Sent1";
				}
				else if (rStr != rStr2) {
					infOutput.textContent = "ERROR: The r-part in Sent2 [" + rStr2 + "] does not match the r-part [" + rStr + "] in Sent1";
				}
				else {
					infOutput.textContent = "(" + qStr + ")" + String.fromCharCode(8744) + "(" + sStr + ")";
					infAddButton.disabled = false;
				}
			}
		}
	}
}

function setSentence1() {
	var selID = premiseList.selectedIndex;
	if (selID >= 0) {
		infSent1.textContent = premiseList.item(selID).text;
		rplSent.textContent = premiseList.item(selID).text;
		infRuleID1.textContent = selID + 1;
		rplRuleID.textContent = selID + 1;
	}
}

function setSentence2() {
	var selID = premiseList.selectedIndex;
	if (selID >= 0) {
		infSent2.textContent = premiseList.item(selID).text;
		infRuleID2.textContent = selID + 1;
	}
	return false;
}

function addPremise(id) {
	var textSource = document.getElementById(id);
	var textString = "";
	if (id == "newPremise") {
		textString = textSource.value;
	}
	else {
		textString = textSource.textContent;
	}
	
	var i;
	for (i = 0; i < premiseList.length; i++) {
		if (textString == premiseList.options[i].text) {
			break;
		}
	}
	if (i >= premiseList.length) {
		var newOption = document.createElement("option");
		newOption.text = textString;
		premiseList.add(newOption);
		var size = premiseList.length;
		if (size < 2) size = 2;
		premiseList.size = size;
		if (id == "newPremise") {
			newPremise.value = "";
			newPremise.focus();
		}
		
		var stepStr = "premise";
		if (id == "infOutput") {
			stepStr = infRuleID1.textContent + "," + infRuleID2.textContent + ", " + infRules.value;
		}
		else if (id == "rplOutput") {
			var rplCode = rplRules.value.split('_');
			stepStr = rplRuleID.textContent + ", " + rplCode[0];
		}
		newOption = document.createElement("option");
		newOption.text = stepStr;
		document.getElementById('proofStep').add(newOption);
	}
}

function showingProofStep() {
	var stepList = document.getElementById('proofStep');
	var textString = "<table border=0>";
	var id = 1;
	var i;
	for (i = 0; i < premiseList.length; i++) {
		textString = textString + "<tr><td>" + id + ". " + premiseList.options[i].text + "</td><td>" + stepList.options[i].text;
		if (i == premiseList.length - 1) {
			textString = textString + "#";
		}
		textString = textString + "</td></tr>";
		id++;
	}
	textString = textString + "</table>";
	document.getElementById('proofStepText').innerHTML = textString;
}

function addSymbol2Str(n) {
	var str = newPremise.value;
	str = str + String.fromCharCode(n);
	newPremise.value = str; 
	newPremise.focus();
}
function addSymbolAnd() { addSymbol2Str(8743); }
function addSymbolOr() { addSymbol2Str(8744); }
function addSymbolImply() { addSymbol2Str(8594); }
function addSymbolEquiv() { addSymbol2Str(8596); }
function addSymbolNot() { addSymbol2Str(172); }

function startProving() {
	newPremise.disabled = true; 
	buttonOr.disabled = true; 
	buttonAnd.disabled = true; 
	buttonImply.disabled = true; 
	buttonEquiv.disabled = true; 
	buttonNot.disabled = true; 
	buttonAddPremise.disabled = true; 
	buttonStartProve.disabled = true; 
	
	infRules.disabled = false;
	document.getElementById('infSubmitButton').disabled = false;
	infAddButton.disabled = false;
	rplRules.disabled = false;
	document.getElementById('rplSubmitButton').disabled = false;
	rplAddButton.disabled = false;
}