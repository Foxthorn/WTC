using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tank : MonoBehaviour {

	public float speed = 6f;
	public float rotationSpeed = 5f;
	public float mouseSpeed = 5f;
	public float range = 50f;
	public GameObject missle;
	public GameObject machineGun;
	public AudioClip[] gunShot = new AudioClip[3];
	public int missleAmmo = 5;

	float timePassed;
	float rechargeTime = 10f;

	float gravity = 9.8f;
	float vertical;
	float horizontal;
	float yaw;
	float boost = 50f;
	bool boostActive = false;
	Transform cannon;
	Vector3 direction = Vector3.zero;
	CharacterController characterController;
	AudioSource source;

	void Start () {
		characterController = GetComponent<CharacterController>();
		cannon = transform.GetChild(1);
		source = GetComponent<AudioSource>();
	}
	
	// Update is called once per frame
	void FixedUpdate () {
		if (Input.GetKeyDown(KeyCode.Mouse0) && missleAmmo > 0 && timePassed >= 3f)
		{
			ShootMissle();
			timePassed = 0f;
		}
		else if (missleAmmo <= 0)
			source.Play();
		if (Input.GetKey(KeyCode.Mouse1))
		{
			ShootMachineGun();
		}
		if (characterController.isGrounded) {
			vertical = Input.GetAxis("Vertical");
			horizontal = Input.GetAxis("Horizontal");
			MoveComponents();
			RotateComponents();
		}
		if (Input.GetKey(KeyCode.LeftShift) && boost > 0f && vertical != 0)
		{
			boost -= 1f;
			boostActive = true;
			timePassed = 0f;
		}
		if (boost <= 0)
			boostActive = false;
		if (timePassed >= rechargeTime) {
			timePassed = 0f;
			boost = 50f;
		}
		timePassed += Time.deltaTime;
		direction.y -= gravity * Time.deltaTime;
		characterController.Move(direction * Time.deltaTime);
	}

	void ShootMissle()
	{
		source.PlayOneShot(gunShot[1]);
		RaycastHit hit;
		if (Physics.Raycast(cannon.position, -cannon.up, out hit, range))
		{
			missle.transform.position = hit.point;
			missle.GetComponent<ParticleSystem>().Play();
		}
	}

	void ShootMachineGun()
	{
		source.PlayOneShot(gunShot[0]);
		RaycastHit hit;
		if (Physics.Raycast(cannon.position, -cannon.up, out hit, range))
		{
			machineGun.transform.position = hit.point;
			machineGun.GetComponent<ParticleSystem>().Play();
		}
	}

	void RotateComponents()
	{
        yaw += mouseSpeed * (Input.GetAxis("Mouse X"));
		while (yaw < 0f) {
            yaw += 360f;
        }
        while (yaw >= 360f) {
            yaw -= 360f;
        }
        cannon.eulerAngles = new Vector3(-90f, yaw, 0f);
		transform.Rotate(transform.up * horizontal * rotationSpeed);

	}

	void MoveComponents()
	{
		Vector3 moveForward = transform.forward * vertical;
		direction = moveForward.normalized;
		if (boostActive)
			direction *= speed * 2f;
		else
			direction *= speed;
	}
}
