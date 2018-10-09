using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class doorController : MonoBehaviour {

	public GameObject door;
	public GameObject screen;
	public Material mat;
	
	MeshRenderer mesh;
	bool isPlayerPresent = false;

	// Use this for initialization
	void Start () {
		mesh = screen.GetComponent<MeshRenderer>();
	}
	
	// Update is called once per frame
	void Update () {
		if (isPlayerPresent)
		{
			mesh.material = mat;
			if ( door.transform.position.z < 7.3)
			{
				door.transform.Translate(-transform.forward * 1f * Time.deltaTime);
			}
		}
	}

	void OnTriggerEnter(Collider col)
	{
		if (col.transform.tag == "MainCamera" && cameraMovement.cm.holdingKeycard)
		{
			isPlayerPresent = true;
		}
	}
}
