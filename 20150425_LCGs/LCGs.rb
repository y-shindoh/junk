#! /usr/bin/ruby
# -*- coding: utf-8; tab-width: 4 -*-
# Author: Yasutaka SHINDOH

require 'optparse'

############################################################

class LCGs
    def initialize(a, b, m, x0)
        @data = [ x0 ]
        m.times { |i|
            v = (a * @data.last + b) % m
            break if x0 == v
            @data << v
        }
        @n = @data.length
    end

    def get(i)
        i %= @n
        @data[i]
    end
end

option = OptionParser::new

a = 3
option.on('-A number', Integer) { |n|
    a = n
}

b = 5
option.on('-B number', Integer) { |n|
    b = n
}

m = 13
option.on('-M number', Integer) { |n|
    m = n
}

x0 = 8
option.on('-X number', Integer) { |n|
    x0 = n
}

option.parse!(ARGV)

############################################################

object = LCGs::new(a, b, m, x0)

if m <= x0 then
    warn("Found invalid arguments!")
    exit(false)
end

printf("X_i = (%d * X_i-1 + %d) %% %d\n", a, b, m)
printf("X_0 = %d\n", x0)

ARGV.each { |v|
    v = v.to_i
    printf("X_%d = %d\n", v, object.get(v))
}
