using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DisplayTowerInfo : MonoBehaviour {

	public GameObject tower;
	towerScript towerScript;

	void Start () {
		towerScript = tower.GetComponent<towerScript>();
	}
	
	// Update is called once per frame
	void Update () {
		string damage = "- Damage: " + towerScript.damage.ToString() + '\n';
		string cost = "- Cost: " + towerScript.energy.ToString() + '\n';
		string range = "- Range: " + towerScript.range.ToString() + '\n';
		string cooldown = "- CD: " + towerScript.fireRate.ToString() + '\n';
		var text = GetComponent<Text>();
		text.text = damage + cost + range + cooldown;
	}
}
