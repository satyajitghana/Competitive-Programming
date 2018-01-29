import sys
import string

ALPHABET = string.ascii_lowercase
ALPHABET_SET = set(ALPHABET)
PLAINTEXT = 'the quick brown fox jumps over the lazy dog'

def read_num():
    return int(sys.stdin.readline())


def load_case():
    case = []

    for line in sys.stdin:
        if line == '' or line =='\n':
            break
        else:
            case.append(line.rstrip())

    return case


def has_same_spaces(plain, cipher):
    if len(plain) != len(cipher):
        return False

    if plain.count(' ') != cipher.count(' '):
        return False

    for p, c in zip(plain, cipher):
        if p==' ' and c != p:
            return False

    return True


def has_all_chars(cipher):
    return set(cipher.replace(' ', '')) == ALPHABET_SET


def substitute(line, subs):
    return "".join(subs[c] for c in line)


def decode(case):
    key = None
    for line in case:
        if not has_same_spaces(PLAINTEXT, line):
            continue
        if not has_all_chars(line):
            continue

        key = line
        break

    if key is None:
        return None

    subs = {}
    for k, p in zip(key, PLAINTEXT):
        subs[k] = p

    dec = []
    for line in case:
        dec.append(substitute(line, subs))

    return dec


if __name__ == '__main__':

    cases = read_num()

    sys.stdin.readline()

    for i in range(cases):
        dec = decode(load_case())
        if not dec:
            print('No solution.')
        else:
            for line in dec:
                print(line)

        if i+1<cases:
            print('')
