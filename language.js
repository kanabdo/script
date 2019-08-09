	/**
	This file allow the translation of a few words between Eglish and French.
	See test_language.html on how to use it.
	**/
var Messages = {
	
	englishLanguage : "English",
	frenchLanguage : "French",
	quiSommesNous: "About Us?",
	termesDutilisaton: "Terms and Conditions",
	enregistrement: "Registration",
	notreContact: "Contact Us",
	share_label: "Share",
	call_label: "CALL",
	email_label: "EMAIL",
	chat_label: "CHAT",
	direction_label: "DIRECTION",
	appointment_label: "RENDEZ-VOUS"
};

function select_languages(){
	
	var _language = document.getElementById("select_languages").value;
	changeLanguageTo(_language);
    console.log("The language changed to:" + _language);
}

function changeLanguageTo(_lang) {
	if (typeof(_lang)!="string")
		_lang = $("#languages").val();
	
    switch (_lang){
    	case "english":
    		setEnglish();
    		break;
    	case "french":
    		setFrench();
    		break;
    }

	$("#englishLanguage").html(Messages.englishLanguage);
	$("#frenchLanguage").html(Messages.frenchLanguage);
	$("#quiSommesNous").html(Messages.quiSommesNous);
	$("#termesDutilisaton").html(Messages.termesDutilisaton);
	$("#enregistrement").html(Messages.enregistrement);
	$("#notreContact").html(Messages.notreContact);
	$("#share_label").html(Messages.share_label);
	$("#call_label").html(Messages.call_label);
	$("#email_label").html(Messages.email_label);
	$("#chat_label").html(Messages.chat_label);
	$("#direction_label").html(Messages.direction_label);
	$("#appointment_label").html(Messages.appointment_label);
}

function setEnglish(){
	
	Messages.englishLanguage = "English";
	Messages.frenchLanguage = "French";
	Messages.quiSommesNous = "About Us";
	Messages.termesDutilisaton = "Terms and Conditions";
	Messages.enregistrement = "Registration";
	Messages.notreContact = "Contact Us";
	Messages.share_label = "Share"; 
	Messages.call_label= "CALL";
	Messages.email_label= "EMAIL";
	Messages.chat_label="CHAT";
	Messages.direction_label= "DIRECTION";
	Messages.appointment_label= "APPOINTMENT";

}

function setFrench(){
	
	Messages.englishLanguage = "Anglais";
	Messages.frenchLanguage = "Francais";
	Messages.quiSommesNous = "Qui sommes-nous?";
	Messages.termesDutilisaton = "Termes d'utilisaton";
	Messages.enregistrement = "Enregistrement";
	Messages.notreContact = "Notre contact";
	Messages.share_label = "Partager"; 
	Messages.call_label= "APPELER";
	Messages.email_label= "EMAIL";
	Messages.chat_label= "CHAT";
	Messages.direction_label= "DIRECTION";
	Messages.appointment_label= "RENDEZ-VOUS";
}


