#! /usr/bin/ruby -Ku
# -*- coding: utf-8 -*-

require 'set'

SYMBOLS = [ '+', '-', '*', '/' ]


############################################################
## 補助関数

def fill_symbols(input_char, index, neighbor, output_symbol)
    if index < input_char.length then
        SYMBOLS.each { |s|
            flag = true
            c = input_char[index]
            neighbor[c].each { |d|
                r = output_symbol[d]
                next unless r
                next if s != r
                flag = false
                break
            }
            if flag then
                output_symbol[c] = s
                flag = fill_symbols(input_char, index + 1, neighbor, output_symbol)
                return true if flag
                output_symbol.delete(c)
            end
        }
        return false
    else
        return true
    end
end


############################################################
## 入力

table = Array::new

STDIN.each_line { |line|
    line.strip!
    break if line.empty?
    table << line.split(//)
}


############################################################
## 隣接文字の抽出

h = table.length
w = table.first.length

neighbor = Hash::new

table.each_index { |i|
    table[i].each_index { |j|
        a = table[i][j]
        neighbor[a] = Set::new unless neighbor[a]
        neighbor[a] << table[i-1][j] if 0 < i
        neighbor[a] << table[i][j-1] if 0 < j
        neighbor[a] << table[i][j+1] if j + 1 < w
        neighbor[a] << table[i+1][j] if i + 1 < h
    }
}

neighbor.each_pair { |k, v|
    v.delete(k)
}

input_char = neighbor.keys
input_char.sort!


############################################################
## 出力文字の探索

output_symbol = Hash::new

fill_symbols(input_char, 0, neighbor, output_symbol)


############################################################
## 出力

if 0 < output_symbol.length then
    table.each_index { |i|
        table[i].each_index { |j|
            a = table[i][j]
            print(output_symbol[a])
        }
        puts('')
    }
else
    warn "[ERROR] invalid!"
end
