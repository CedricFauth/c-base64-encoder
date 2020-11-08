import base64
import sys


def main():
	if len(sys.argv) != 2:
		return 0
	message_bytes = sys.argv[1].encode('ascii')
	enc = base64.b64encode(message_bytes)
	print(enc)

if __name__ == '__main__':
	main()
