using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DisplayPlayerInfo : MonoBehaviour {

	// Update is called once per frame
	void Update () {
		string energy = "- Energy: " + gameManager.gm.playerEnergy.ToString() + '\n';
		string hp = "- Health: " + gameManager.gm.playerHp.ToString() + '\n';
		var text = GetComponent<Text>();
		text.text = energy + hp;
	}
}
